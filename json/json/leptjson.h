#ifndef JSON_H_
#define JSON_H_

#include <iostream>
#include <cassert>
//避免以下写法
// #define EXPECT(c, ch)             \
//     do                            \
//     {                             \
//         assert(*c->json == (ch)); \
//         c->json++;                \
//     } while (0)

//枚举类型，对应着json语句的各种类型
typedef enum
{
    LEPT_NULL,
    LEPT_FALSE,
    LEPT_TRUE,
    LEPT_NUMBER,
    LEPT_STRING,
    LEPT_ARRAY,
    LEPT_OBJECT
} lept_type;

enum
{
    // LEPT_PARSE_OK 无错误
    LEPT_PARSE_OK = 0,

    //对应三种错误码

    // LEPT_PARSE_EXPECT_VALUE   json后只有空白
    LEPT_PARSE_EXPECT_VALUE,
    // LEPT_PARSE_INVALID_VALUE   非上面几种字面值
    LEPT_PARSE_INVALID_VALUE,
    // lept_PARSE_ROOT_NOT_SINGULAR 一个值之后，在空白之后还有其他字符
    LEPT_PARSE_ROOT_NOT_SINGULAR
};

//json 文本数据
typedef struct
{
    const char *json;
} lept_context;

//json 内对应的数据类型
typedef struct
{
    double n;
    lept_type type;
} lept_value;

//根据第一个字符判断当前指向json字符的类型
inline void EXPECT(lept_context *c, const char ch)
{
    //对应数据类型相同，直接进行下一个元素
    assert(*c->json == ch);
    //指向下一个字符
    c->json++;
}

//状态码，对应检测的四种状态
static int lept_parse_literal(lept_context *c, lept_value *v, const char *literal, lept_type type);
static void lept_parse_whitespace(lept_context *c);
static int lept_parse_null(lept_context *c, lept_value *v);
static int lept_parse_false(lept_context *c, lept_value *v);
static int lept_parse_true(lept_context *c, lept_value *v);
static int lept_parse_value(lept_context *c, lept_value *v);
static int lept_parse_number(lept_context *c, lept_value *v);
/*************************************************************/

//将一个json字符串转化为json值
int lept_parse(lept_value *v, const char *json)
{
    lept_context c;
    int ret = LEPT_TRUE;
    assert(v != nullptr);
    c.json = json;
    v->type = LEPT_NULL;
    lept_parse_whitespace(&c);
    while ((ret = lept_parse_value(&c, v)) == LEPT_PARSE_OK)
    {
        lept_parse_whitespace(&c);
        if (*c.json != '\0')
            return LEPT_PARSE_ROOT_NOT_SINGULAR;
    }
    return ret;
}
/* ws = *(%x20 / %x09 / %x0A / %x0D) */
//跳过空白
static void lept_parse_whitespace(lept_context *c)
{
    const char *p = c->json;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
        p++;
    c->json = p;
}

/* null  = "null" */
static int lept_parse_null(lept_context *c, lept_value *v)
{ //判断第一个字母是否是‘n’
    // EXPECT(c, 'n');
    // //如果后面字符符合'u','l','l'
    // if (c->json[0] != 'u' || c->json[1] != 'l' || c->json[2] != 'l')
    //     return LEPT_PARSE_INVALID_VALUE;
    // //继续指向null后面的元素
    // c->json += 3;
    // //表明当前字符类型是null
    // v->type = LEPT_NULL;
    // //字符判断正确
    // return LEPT_PARSE_OK;
    return lept_parse_literal(c, v, "null", LEPT_NULL);
}

static int lept_parse_false(lept_context *c, lept_value *v)
{
    // //判断第一个字符是否是'f'
    // EXPECT(c, 'f');
    // //如果后面的字符是‘a‘、’l’、's'、'e'
    // if (c->json[0] != 'a' || c->json[1] != 'l' || c->json[2] != 's' || c->json[3] != 'e')
    //     return LEPT_PARSE_INVALID_VALUE;
    // //继续指向false后面的元素
    // c->json += 4;
    // //表明当前的字符是false
    // v->type = LEPT_FALSE;
    // return LEPT_PARSE_OK;
    return lept_parse_literal(c,v,"false",LEPT_FALSE);
}

static int lept_parse_true(lept_context *c, lept_value *v)
{
    // //判断第一个字符是否是't'
    // EXPECT(c, 't');
    // //如果后面的字符是'u','r','e'
    // if (c->json[0] != 'u' || c->json[1] != 'r' || c->json[2] != 'e')
    //     return LEPT_PARSE_INVALID_VALUE;
    // //继续指向ture后面的字符
    // c->json += 3;
    // v->type = LEPT_TRUE;
    // return LEPT_PARSE_OK;
    return lept_parse_literal(c, v, "true", LEPT_TRUE);
}

static int lept_parse_literal(lept_context *c, lept_value *v, const char *literal, lept_type type)
{
    size_t i;
    EXPECT(c, literal[0]);
    for (i = 0; literal[i+1]; i++)
        if (c->json[i] != literal[i+1])
            return LEPT_PARSE_INVALID_VALUE;
    c->json += i;
    v->type = type;
    return LEPT_PARSE_OK;
}
/* value = null / false / true */
/* 提示：下面代码没处理 false / true，将会是练习之一 */
static int lept_parse_value(lept_context *c, lept_value *v)
{
    switch (*c->json)
    {
    case 'n':
        return lept_parse_null(c, v);
    case 'f':
        return lept_parse_false(c, v);
    case 't':
        return lept_parse_true(c, v);
    case '\0':
        return LEPT_PARSE_EXPECT_VALUE;
    default:
        return lept_parse_number(c, v);
    }
}

static int lept_parse_number(lept_context *c, lept_value *v)
{
    const char *p=c->json;
    if (*p == '-')
        p++;
    if (*p == '0')
        p++;
    else
    {
        if (!ISDIGIT1TO9(*p))
            return LEPT_PARSE_INVALID_VALUE;
        for (p++; ISDIGIT(*p); p++)
            ;
    }
    if (*p == '.')
    {
        p++;
        if (!ISDIGIT(*p))
            return LEPT_PARSE_INVALID_VALUE;
        for (p++; ISDIGIT(*p); p++)
            ;
    }
    if (*p == 'e' || *p == 'E')
    {
        p++;
        if (*p == '+' || *p == '-')
            p++;
        if (!ISDIGIT(*p))
            return LEPT_PARSE_INVALID_VALUE;
        for (p++; ISDIGIT(*p); p++)
            ;
    }
    p++;
    while (ISDIGIT(*p))
        p++;

    v->n = strtod(c->json, NULL);
    c->json = p;
    v->type = LEPT_NUMBER;
    return LEPT_PARSE_OK;
}
//访问结果
lept_type lept_get_type(const lept_value *v)
{
    return v->type;
}
double lept_get_number(const lept_value *v)
{
    assert(v != NULL && v->type == LEPT_NUMBER);
    return v->n;
}
#endif //JSON_H_