/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vwprintf with a format string
 *    BadSink : vwprintf without a format string
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
#define CLOSE_SOCKET closesocket
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

typedef struct _CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_67_structType
{
    wchar_t * structFirst;
} CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_67_structType;

#ifndef OMITBAD

static void badVaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vwprintf(data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_67b_badSink(CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    badVaSink(data, data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2BVaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vwprintf(data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_67b_goodG2BSink(CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    goodG2BVaSink(data, data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2GVaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vwprintf(L"%s", args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_67b_goodB2GSink(CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    goodB2GVaSink(data, data);
}

#endif /* OMITGOOD */
