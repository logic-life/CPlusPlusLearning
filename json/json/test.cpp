#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "leptjson.h"
//一个测试框架
static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

//测试方法

//统计测试案例通过的
#define EXPECT_EQ_BASE(equality, expect, actual, format)                                                         \
    do                                                                                                           \
    {                                                                                                            \
        test_count++;                                                                                            \
        if (equality)                                                                                            \
            test_pass++;                                                                                         \
        else                                                                                                     \
        {                                                                                                        \
            fprintf(stderr, "%s:%d: expect:" format " actual:" format "\n", __FILE__, __LINE__, expect, actual); \
            main_ret = 1;                                                                                        \
        }                                                                                                        \
    } while (0)

//实际值如果和预期值不符合就打印通过率和不通过的行数信息
#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")
#define EXPECT_EQ_NUMBER(expect, actual) EXPECT_EQ_BASE((expect)==(actual),expect,actual,"%l")


inline void TEST_ERROR(double error,const char * json){
    lept_value v;
    v.type = LEPT_FALSE;
    EXPECT_EQ_INT(error, lept_parse(&v, json));
    EXPECT_EQ_INT(LEPT_NULL, lept_get_type(&v));
}

inline void TEST_NUMBER(double expect,const char *json){
    lept_value v;
    EXPECT_EQ_INT(LEPT_PARSE_OK,lept_parse(&v,json));
    EXPECT_EQ_INT(LEPT_NUMBER,lept_get_type(&v));
    EXPECT_EQ_NUMBER(expect,lept_get_number(&v));
}

static void test_parse_root_not_singular()
{
    TEST_ERROR(LEPT_PARSE_ROOT_NOT_SINGULAR,"null value");

}

static void test_parse_invalid_value()
{
    TEST_ERROR(LEPT_PARSE_INVALID_VALUE, "nul");
}

static void test_parse_expect_value()
{
    TEST_ERROR(LEPT_PARSE_EXPECT_VALUE, " ");
}

static void test_parse_null()
{
    lept_value v;
    v.type = LEPT_TRUE;
    EXPECT_EQ_INT(LEPT_PARSE_OK, lept_parse(&v, "null"));
    EXPECT_EQ_INT(LEPT_NULL, lept_get_type(&v));
}

static void test_parse_ture()
{
    lept_value v;
    v.type = LEPT_TRUE;
    EXPECT_EQ_INT(LEPT_PARSE_OK, lept_parse(&v, "true"));
    EXPECT_EQ_INT(LEPT_TRUE, lept_get_type(&v));
}

static void test_parse_false()
{
    lept_value v;
    v.type = LEPT_TRUE;
    EXPECT_EQ_INT(LEPT_PARSE_OK, lept_parse(&v, "false "));
    EXPECT_EQ_INT(LEPT_FALSE, lept_get_type(&v));
}





static void test_parse_number(){
    TEST_NUMBER(0.0,"0");
    TEST_NUMBER(0.0,"-0");
    TEST_NUMBER(0.0, "-0.0");
    TEST_NUMBER(1.0, "1");
    TEST_NUMBER(-1.0, "-1");
    TEST_NUMBER(1.5, "1.5");
    TEST_NUMBER(-1.5, "-1.5");
    TEST_NUMBER(3.1416, "3.1416");
    TEST_NUMBER(1E10, "1E10");
    TEST_NUMBER(1e10, "1e10");
    TEST_NUMBER(1E+10, "1E+10");
    TEST_NUMBER(1E-10, "1E-10");
    TEST_NUMBER(-1E10, "-1E10");
    // TEST_NUMBER(1.0000000000000002, "1.0000000000000002");
    // /* minimum denormal */
    // TEST_NUMBER(4.9406564584124654e-324, "4.9406564584124654e-324");
    // TEST_NUMBER(-4.9406564584124654e-324, "-4.9406564584124654e-324");
    // /* Max subnormal double */
    // TEST_NUMBER(2.2250738585072009e-308, "2.2250738585072009e-308");
    // TEST_NUMBER(-2.2250738585072009e-308, "-2.2250738585072009e-308");
    // /* Min normal positive double */
    // TEST_NUMBER(2.2250738585072014e-308, "2.2250738585072014e-308");
    // TEST_NUMBER(-2.2250738585072014e-308, "-2.2250738585072014e-308");
    // /* Max double */
    // TEST_NUMBER(1.7976931348623157e+308, "1.7976931348623157e+308");
    // TEST_NUMBER(-1.7976931348623157e+308, "-1.7976931348623157e+308");
}
static void test_parse()
{
    test_parse_null();
    test_parse_false();
    test_parse_ture();
    test_parse_root_not_singular();
    test_parse_expect_value();
    test_parse_invalid_value();
    test_parse_number();
}

int main()
{

    test_parse();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}