/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_22a.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
int CWE401_Memory_Leak__strdup_wchar_t_22_badGlobal = 0;

void CWE401_Memory_Leak__strdup_wchar_t_22_badSink(wchar_t * data);

void CWE401_Memory_Leak__strdup_wchar_t_22_bad()
{
    wchar_t * data;
    data = NULL;
    {
        wchar_t myString[] = L"myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
    CWE401_Memory_Leak__strdup_wchar_t_22_badGlobal = 1; /* true */
    CWE401_Memory_Leak__strdup_wchar_t_22_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the sink functions. */
int CWE401_Memory_Leak__strdup_wchar_t_22_goodB2G1Global = 0;
int CWE401_Memory_Leak__strdup_wchar_t_22_goodB2G2Global = 0;
int CWE401_Memory_Leak__strdup_wchar_t_22_goodG2BGlobal = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE401_Memory_Leak__strdup_wchar_t_22_goodB2G1Sink(wchar_t * data);

static void goodB2G1()
{
    wchar_t * data;
    data = NULL;
    {
        wchar_t myString[] = L"myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
    CWE401_Memory_Leak__strdup_wchar_t_22_goodB2G1Global = 0; /* false */
    CWE401_Memory_Leak__strdup_wchar_t_22_goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE401_Memory_Leak__strdup_wchar_t_22_goodB2G2Sink(wchar_t * data);

static void goodB2G2()
{
    wchar_t * data;
    data = NULL;
    {
        wchar_t myString[] = L"myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
    CWE401_Memory_Leak__strdup_wchar_t_22_goodB2G2Global = 1; /* true */
    CWE401_Memory_Leak__strdup_wchar_t_22_goodB2G2Sink(data);
}

/* goodG2B() - use goodsource and badsink */
void CWE401_Memory_Leak__strdup_wchar_t_22_goodG2BSink(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack with ALLOCA */
    data = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* Initialize then use data */
    wcscpy(data, L"a string");
    printWLine(data);
    CWE401_Memory_Leak__strdup_wchar_t_22_goodG2BGlobal = 1; /* true */
    CWE401_Memory_Leak__strdup_wchar_t_22_goodG2BSink(data);
}

void CWE401_Memory_Leak__strdup_wchar_t_22_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE401_Memory_Leak__strdup_wchar_t_22_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__strdup_wchar_t_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
