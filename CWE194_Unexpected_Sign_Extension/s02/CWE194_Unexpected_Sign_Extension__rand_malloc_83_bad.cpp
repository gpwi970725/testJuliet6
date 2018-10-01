/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__rand_malloc_83_bad.cpp
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: rand Set data to result of RAND32(), which could be negative
 * GoodSource: Positive integer
 * Sinks: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE194_Unexpected_Sign_Extension__rand_malloc_83.h"

namespace CWE194_Unexpected_Sign_Extension__rand_malloc_83
{
CWE194_Unexpected_Sign_Extension__rand_malloc_83_bad::CWE194_Unexpected_Sign_Extension__rand_malloc_83_bad(short dataCopy)
{
    data = dataCopy;
    /* FLAW: Use a random value that could be less than 0 */
    data = (short)RAND32();
}

CWE194_Unexpected_Sign_Extension__rand_malloc_83_bad::~CWE194_Unexpected_Sign_Extension__rand_malloc_83_bad()
{
    /* Assume we want to allocate a relatively small buffer */
    if (data < 100)
    {
        /* POTENTIAL FLAW: malloc() takes a size_t (unsigned int) as input and therefore if it is negative,
         * the conversion will cause malloc() to allocate a very large amount of data or fail */
        char * dataBuffer = (char *)malloc(data);
        if (dataBuffer == NULL) {exit(-1);}
        /* Do something with dataBuffer */
        memset(dataBuffer, 'A', data-1);
        dataBuffer[data-1] = '\0';
        printLine(dataBuffer);
        free(dataBuffer);
    }
}
}
#endif /* OMITBAD */
