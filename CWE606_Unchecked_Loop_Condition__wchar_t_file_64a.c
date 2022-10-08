/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_file_64a.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: file Read input from a file
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__wchar_t_file_64b_badSink(void * dataVoidPtr);

void CWE606_Unchecked_Loop_Condition__wchar_t_file_64_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgetws(data+dataLen, (int)(100-dataLen), pFile) == NULL)//SLIVER_SOURCE
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    CWE606_Unchecked_Loop_Condition__wchar_t_file_64b_badSink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_file_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Set data to a number less than MAX_LOOP */
    wcscpy(data, L"15");
    CWE606_Unchecked_Loop_Condition__wchar_t_file_64b_goodG2BSink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_file_64b_goodB2GSink(void * dataVoidPtr);

static void goodB2G()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgetws(data+dataLen, (int)(100-dataLen), pFile) == NULL)//SLIVER_SOURCE
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    CWE606_Unchecked_Loop_Condition__wchar_t_file_64b_goodB2GSink(&data);
}

void CWE606_Unchecked_Loop_Condition__wchar_t_file_64_good()
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
    CWE606_Unchecked_Loop_Condition__wchar_t_file_64_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE606_Unchecked_Loop_Condition__wchar_t_file_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif


//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_64a.c:53--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_64b.c:46 YES
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_64a.c:53--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_64b.c:73 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_64a.c:53--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_64b.c:98 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_64a.c:102--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_64b.c:46 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_64a.c:102--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_64b.c:73 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_file_64a.c:102--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_file_64b.c:98 YES
