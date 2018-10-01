/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_char_memcpy_83_bad.cpp
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__malloc_char_memcpy_83.h"

namespace CWE127_Buffer_Underread__malloc_char_memcpy_83
{
CWE127_Buffer_Underread__malloc_char_memcpy_83_bad::CWE127_Buffer_Underread__malloc_char_memcpy_83_bad(char * dataCopy)
{
    data = dataCopy;
    {
        char * dataBuffer = (char *)malloc(100*sizeof(char));
        if (dataBuffer == NULL) {exit(-1);}
        memset(dataBuffer, 'A', 100-1);
        dataBuffer[100-1] = '\0';
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = dataBuffer - 8;
    }
}

CWE127_Buffer_Underread__malloc_char_memcpy_83_bad::~CWE127_Buffer_Underread__malloc_char_memcpy_83_bad()
{
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memcpy(dest, data, 100*sizeof(char));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}
}
#endif /* OMITBAD */
