#ifndef JOGNRTOS_ASSERT_H
#define JOGNRTOS_ASSERT_H


#define STATIC_ASSERT(COND, MSG) typedef char static_assertion_##MSG[(COND)?1:-1]


#endif //JOGNRTOS_ASSERT_H
