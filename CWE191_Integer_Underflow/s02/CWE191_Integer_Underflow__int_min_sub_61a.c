/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_min_sub_61a.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the minimum value for int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
int CWE191_Integer_Underflow__int_min_sub_61b_badSource(int data);

void CWE191_Integer_Underflow__int_min_sub_61_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    data = CWE191_Integer_Underflow__int_min_sub_61b_badSource(data);
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        int result = data - 1;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
int CWE191_Integer_Underflow__int_min_sub_61b_goodG2BSource(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    data = CWE191_Integer_Underflow__int_min_sub_61b_goodG2BSource(data);
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        int result = data - 1;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
int CWE191_Integer_Underflow__int_min_sub_61b_goodB2GSource(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = 0;
    data = CWE191_Integer_Underflow__int_min_sub_61b_goodB2GSource(data);
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > INT_MIN)
    {
        int result = data - 1;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform subtraction.");
    }
}

void CWE191_Integer_Underflow__int_min_sub_61_good()
{
    goodG2B();
    goodB2G();
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
    CWE191_Integer_Underflow__int_min_sub_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_min_sub_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
