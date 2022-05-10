#include "gtest/gtest.h"

#include "../headers/HuffmanCode/HuffmanCode.h"
#include <string>
#include <vector>

class TestHuffmanCode : public ::testing::Test {
protected:
    HuffmanCode code_;
    std::vector<std::string> sourceStr_;
    std::vector<std::string> encodedStr_;
public:
    TestHuffmanCode() {
        sourceStr_ = std::vector<std::string>(5, "");
        sourceStr_[0] = "1234";
        sourceStr_[1] = "122333";
        sourceStr_[2] = "122333444455555";
        sourceStr_[3] = "123456";
        sourceStr_[4] = "it is test string";

        encodedStr_ = std::vector<std::string>(5, "");
        encodedStr_[0] = "01100011";
        encodedStr_[1] = "111010000";
        encodedStr_[2] = "111110110101010010101010000000000";
        encodedStr_[3] = "0010101000011011";
        encodedStr_[4] = "111000011001000100100001100000011001011101110110";
    }

    ~TestHuffmanCode() = default;
};

TEST_F(TestHuffmanCode, encode) {
    for (int i = 0; i < 5; ++i) {
        code_.encode(sourceStr_[i]);
        ASSERT_EQ(encodedStr_[i], code_.getEncodedString());
    }
}

TEST_F(TestHuffmanCode, decode) {
    for (int i = 0; i < 5; ++i) {
        code_.encode(sourceStr_[i]);
        auto table(code_.getTable());
        code_.decode(encodedStr_[i], table);
        ASSERT_EQ(sourceStr_[i], code_.getSourceString());
    }
}

TEST_F(TestHuffmanCode, getCountBytesByTheSourceString) {
    for (int i = 0; i < 5; ++i) {
        code_.encode(sourceStr_[i]);
        ASSERT_EQ(sourceStr_[i].size() * 8, code_.getCountBytesByTheSourceString());
    }
}

TEST_F(TestHuffmanCode, getCountBytesByTheEncodedString) {
    for (int i = 0; i < 5; ++i) {
        code_.encode(sourceStr_[i]);
        ASSERT_EQ(encodedStr_[i].size(), code_.getCountBytesByTheEncodedString());
    }
}

TEST_F(TestHuffmanCode, getCompressionRatio) {
    for (int i = 0; i < 5; ++i) {
        code_.encode(sourceStr_[i]);
        ASSERT_EQ(static_cast<double>(sourceStr_[i].size() * 8) / static_cast<double>(encodedStr_[i].size()),
                  code_.getCompressionRatio());
    }
}
