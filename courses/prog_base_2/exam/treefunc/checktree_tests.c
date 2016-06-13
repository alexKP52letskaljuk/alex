#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "../checktree.h"

static void checktree__str__validTree (void** state)
{
    char* str = "( () () ( ()  ( \t () ) ))";
    assert_int_equal ( checktree (str), 1 );
}

static void checktree__null_str__validTree (void** state)
{
    char* str = "";
    assert_int_equal ( checktree (str), 1 );
}

static void checktree__str_invalid_symbols__invalidTree (void** state)
{
    char* str = " ()  () (s)";
    assert_int_equal ( checktree (str), 0 );
}

static void checktree__str_with_opened_grater_than_closed__invalidTree (void** state)
{
    char* str = "( () () ( ( (  ((  ))) )";
    assert_int_equal ( checktree (str), 0 );
}

static void checktree__str_with_closed_grater_than_opened__invalidTree (void** state)
{
    char* str = "() () () () )) () ( () () ()  ) ()";
    assert_int_equal ( checktree (str), 0 );
}

void moduleTests_checktree(void) {
    const UnitTest tests[] =
    {
        unit_test (checktree__str__validTree),
        unit_test (checktree__null_str__validTree),
        unit_test (checktree__str_invalid_symbols__invalidTree),
        unit_test (checktree__str_with_opened_grater_than_closed__invalidTree),
        unit_test (checktree__str_with_closed_grater_than_opened__invalidTree)
    };
    run_tests(tests);
}
