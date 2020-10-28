/*
 * Release: 2016-01-01
 *
 * Example from MISRA C:2012 ( THIS IS NOT A TEST SUITE )
 *
 * Copyright HORIBA MIRA Limited.
 *
 * See file READ_ME.txt for full copyright, license and release instructions.
 */

 /*
  * R.20.8
  *
  * The controlling expression of a #if or #elif preprocessing directive shall
  * evaluate to 0 or 1
  */

#define N 6345
#define NX N
#define NXX NX
#define NUM NXX
#define NUM0 0
#define NUM1 1
#define COND0 NUM1*(21/42 < NUM1? 2:3)
#define COND1 0 * COND0
#define COND2 (COND0 * 0)
#define COND2 0 * COND0
#define COND3 NUM0 < NUM1
#define COND4 NUM0 < NUM1 && NUM0 != 123
#define COND5 NUM1
#define COND6 NUM0
#define COND7 COND0

#if 0                 // Compliant     
static const char* const str = "null";
#elif 1				  // Compliant     
static const char* const str = "1";
#else
static const char* const str = "null";
#endif

#if 0                 // Compliant     
static const char* const strx = "null";
#elif NUM				  // Non-Compliant     
static const char* const strx = "1";
#else
static const char* const strx = "null";
#endif

#if NUM0            // Compliant     
static const char* const str0 = "1";
#elif NUM1			// Compliant     
static const char* const str0 = "null";
#else
static const char* const str0 = "null";
#endif

#if 9242            //Non-Compliant     
static const char* const str1 = "1";
#elif 0*12*4233			// NON-Compliant     
static const char* const str1 = "null";
#else
static const char* const str1 = "null";
#endif


#if COND1           // Non-Compliant : Skipped due to expr complexity
static const char* const str2 = "1";
#elif COND0			// Non-Compliant : Skipped due to expr complexity
static const char* const str2 = "null";
#else
static const char* const str2 = "null";
#endif

#if COND2            // Non-Compliant : Skipped due to expr complexity    
static const char* const str3 = "1";
#elif COND3			// Non-Compliant  : Skipped due to expr complexity
static const char* const str3 = "null";
#else
static const char* const str3 = "null";
#endif

#if COND4 * 0       // Non-Compliant : Skipped due to expr complexity
static const char* const str4 = "1";
#elif COND5			//Compliant     
static const char* const str4 = "null";
#else
static const char* const str4 = "null";
#endif

#if COND6            // Compliant     
static const char* const str5 = "1";
#elif COND7			// Non-Compliant : Skipped due to expr complexity
static const char* const str5 = "null";
#else
static const char* const str5 = "null";
#endif


#if COND6 && COND2           // Non-Compliant : Skipped due to expr complexity     
static const char* const str6 = "1";
#elif COND7	&& COND2		// Non-Compliant : Skipped due to expr complexity     
static const char* const str6 = "null";
#else
static const char* const str6 = "null";
#endif


/* end of R_20_08.c */