/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_32.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Positive integer
 * Sink: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_32_bad()
{
    int data;
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    /* Initialize data */
    data = -1;
    {
        int data = *dataPtr1;
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
        {
            char source[100];
            char dest[100] = "";
            memset(source, 'A', 100-1);
            source[100-1] = '\0';
            if (data < 100)
            {
                /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
                 * the sign conversion could result in a very large number */
                strncpy(dest, source, data);
                dest[data] = '\0'; /* strncpy() does not always NULL terminate */
            }
            printLine(dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    /* Initialize data */
    data = -1;
    {
        int data = *dataPtr1;
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
        {
            char source[100];
            char dest[100] = "";
            memset(source, 'A', 100-1);
            source[100-1] = '\0';
            if (data < 100)
            {
                /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
                 * the sign conversion could result in a very large number */
                strncpy(dest, source, data);
                dest[data] = '\0'; /* strncpy() does not always NULL terminate */
            }
            printLine(dest);
        }
    }
}

void CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_32_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
