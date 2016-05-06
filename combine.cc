#include <iostream>
#include <string.h>

template<typename E, int MAX_SEL = 32>
class Combine {
public:
    Combine (E *arr, int len, int sel) {
        this->arr = arr;
        this->len = len;
        this->sel = sel;
    };

    /*
     * 层次索引皆从0开始
     */

    // 获取i层的最大索引数
    inline int get_max_index (int i) {
        return len - sel + i;
    }
    // 检查i层索引溢出
    inline void check_overflow (int i) {
        if (poi[i] > get_max_index(i)) {
            if (i == 0) { // 第0位索引溢出，组合数列举结束
                exit = true;
                return;
            }
            increase_poi(i-1);
            poi[i] = poi[i-1] + 1;
        }
    }
    // 增加第i层的索引指针
    inline void increase_poi(int i) {
        poi[i]++;
        check_overflow(i);
    }
    // 打印深度指针中所组合的序列
    void print () {
        for (int i = 0; i < sel; ++i)
            std::cout << this->arr[poi[i]] << ' ';
        std::cout << std::endl;
    }
    // 开始输出组合数
    void begin () {
        // 初始化深度指针
        for (int i = 0; i < sel; ++i)
            poi[i] = i;
        for (this->exit = false; ; ) {
            print();
            increase_poi(sel-1);
            if (exit) break;
        }
    }

private:
    E   * arr;          // 待组合数据的指针
    int   len;          // . . . . . . 长度，相当于m
    int   sel;          // 相当于m选n中的n
    int   poi[MAX_SEL]; // 深度指针
    bool  exit;         // 退出标志
};

int main(int argc, const char *argv[]) {
    typedef Combine<char> CombineChar;
    char *str = (char *)"abcdefg";
    CombineChar com(str, strlen(str), 2);
    com.begin();
    return 0;
}
