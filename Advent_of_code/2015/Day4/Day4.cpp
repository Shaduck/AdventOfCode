
#include "Day4.h"

#include "Utils/TMD5.h"

#include "Utils/md5.h"
// 
// /* MDDRIVER.C - test driver for MD2, MD4 and MD5
// */
// 
// /* Copyright (C) 1990-2, RSA Data Security, Inc. Created 1990. All
// rights reserved.
// 
// RSA Data Security, Inc. makes no representations concerning either
// the merchantability of this software or the suitability of this
// software for any particular purpose. It is provided "as is"
// without express or implied warranty of any kind.
// 
// These notices must be retained in any copies of any part of this
// documentation and/or software.
// */
// 
// /* The following makes MD default to MD5 if it has not already been
// defined with C compiler flags.
// */
// // #ifndef MD
// // #define MD 5
// // #endif
// 
// #include <stdio.h>
// #include <time.h>
// #include <string.h>
// #include "global.h"
// 
// // #if MD == 2
// // #include "md2.h"
// // #endif
// // #if MD == 4
// // #include "md4.h"
// // #endif
// // #if MD == 5
// 
// const int MD = 5;
// 
// #include "md5.h"
// //#endif
// 
// 
// 
// /* Length of test block, number of test blocks.
// */
// // #define TEST_BLOCK_LEN 1000
// // #define TEST_BLOCK_COUNT 1000
// 
// static void MDString (char *);
// //static void MDTimeTrial ();
// static void MDTestSuite ();
// static void MDFile (char *);
// static void MDFilter ();
// static void MDPrint (unsigned char [16]);
// 
// /*
// #if MD == 2
// #define MD_CTX MD2_CTX
// #define MDInit MD2Init
// #define MDUpdate MD2Update
// #define MDFinal MD2Final
// #endif
// #if MD == 4
// #define MD_CTX MD4_CTX
// #define MDInit MD4Init
// #define MDUpdate MD4Update
// #define MDFinal MD4Final
// #endif
// #if MD == 5
// #define MD_CTX MD5_CTX
// #define MDInit MD5Init
// #define MDUpdate MD5Update
// #define MDFinal MD5Final
// #endif
// */
// 
// /* Main driver.
// 
// Arguments (may be any combination):
// -sstring - digests string
// -t       - runs time trial
// -x       - runs test script
// filename - digests file
// (none)   - digests standard input
// */
// int locmain (int argc, char *argv[])
// {
// 	int i;
// 
// 	if (argc > 1)
// 	{
// 		for (i = 1; i < argc; i++)
// 		{
// 			if (argv[i][0] == '-' && argv[i][1] == 's')
// 			{
// 				MDString (argv[i] + 2);
// 			}
// 			else if (strcmp (argv[i], "-t") == 0)
// 			{
// 				// MDTimeTrial ();
// 			}
// 			else if (strcmp (argv[i], "-x") == 0)
// 			{
// 				MDTestSuite ();
// 			}
// 			else
// 			{
// 				MDFile (argv[i]);
// 			}
// 		}
// 	}
// 	else
// 	{
// 		MDFilter ();
// 	}
// 
// 	return (0);
// }
// 
// /* Digests a string and prints the result.
// */
// static void MDString (char *string)
// {
// 	MD5_CTX context;
// 	unsigned char digest[16];
// 	unsigned int len = strlen (string);
// 
// 	MD5Init (&context);
// 
// 	MD5Update (&context, reinterpret_cast<unsigned char *>(string), len);
// 
// 	MD5Final (digest, &context);
// 
// 
// 	printf ("MD5 (\"%s\") = ", string);
// 	MDPrint (digest);
// 	printf ("\n");
// }
// 
// /* Measures the time to digest TEST_BLOCK_COUNT TEST_BLOCK_LEN-byte
// blocks.
// */
// // static void MDTimeTrial ()
// // {
// // 	MD5_CTX context;
// // 	time_t endTime, startTime;
// // 	unsigned char block[TEST_BLOCK_LEN], digest[16];
// // 	unsigned int i;
// // 
// // 	printf
// // 		("MD%d time trial. Digesting %d %d-byte blocks ...", MD,
// // 			TEST_BLOCK_LEN, TEST_BLOCK_COUNT);
// // 
// // 	/* Initialize block */
// // 	for (i = 0; i < TEST_BLOCK_LEN; i++)
// // 		block[i] = (unsigned char)(i & 0xff);
// // 
// // 	/* Start timer */
// // 	time (&startTime);
// // 
// // 	/* Digest blocks */
// // 	MD5Init (&context);
// // 	for (i = 0; i < TEST_BLOCK_COUNT; i++)
// // 		MD5Update (&context, block, TEST_BLOCK_LEN);
// // 	MD5Final (digest, &context);
// // 
// // 	/* Stop timer */
// // 	time (&endTime);
// // 
// // 	printf (" done\n");
// // 	printf ("Digest = ");
// // 	MDPrint (digest);
// // 	printf ("\nTime = %ld seconds\n", (long)(endTime-startTime));
// // 	printf
// // 		("Speed = %ld bytes/second\n",
// // 			(long)TEST_BLOCK_LEN * (long)TEST_BLOCK_COUNT/(endTime-startTime));
// // }
// 
// /* Digests a reference suite of strings and prints the results.
// */
// static void MDTestSuite ()
// {
// 	printf ("MD%d test suite:\n", MD);
// 
// 	MDString ("");
// 	MDString ("a");
// 	MDString ("abc");
// 	MDString ("message digest");
// 	MDString ("abcdefghijklmnopqrstuvwxyz");
// 	MDString
// 	("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
// 	MDString
// 	("1234567890123456789012345678901234567890\
// 1234567890123456789012345678901234567890");
// }
// 
// /* Digests a file and prints the result.
// */
// static void MDFile (char *filename)
// {
// 	FILE *file;
// 	MD5_CTX context;
// 	int len;
// 	unsigned char buffer[1024], digest[16];
// 
// 	if ((file = fopen (filename, "rb")) == NULL)
// 		printf ("%s can't be opened\n", filename);
// 
// 	else {
// 		MD5Init (&context);
// 		while (len = fread (buffer, 1, 1024, file))
// 			MD5Update (&context, buffer, len);
// 		MD5Final (digest, &context);
// 
// 		fclose (file);
// 
// 		printf ("MD%d (%s) = ", MD, filename);
// 		MDPrint (digest);
// 		printf ("\n");
// 	}
// }
// 
// /* Digests the standard input and prints the result.
// */
// static void MDFilter ()
// {
// 	MD5_CTX context;
// 	int len;
// 	unsigned char buffer[16], digest[16];
// 
// 	MD5Init (&context);
// 	while (len = fread (buffer, 1, 16, stdin))
// 	{
// 		MD5Update (&context, buffer, len);
// 	}
// 
// 	MD5Final (digest, &context);
// 
// 	MDPrint (digest);
// 	printf ("\n");
// }
// 
// /* Prints a message digest in hexadecimal.
// */
// static void MDPrint (unsigned char digest[16])
// {
// 	unsigned int i;
// 
// 	for (i = 0; i < 16; i++)
// 		printf ("%02x", digest[i]);
// }
// 

namespace nsDay04
{

bool CompareMyMD5(TMD5 const &pmine, std::string const &expectedresult)
{
	auto v1 = pmine.String();

	return v1 == expectedresult;

// 	for(int i = 0; i < 16; ++i)
// 	{
// 		auto v1 = pmine.String(i);
// 		auto v2 = expectedresult[i];
// 
// 		//if(pmine.Value(i) != expectedresult[i])
// 		if(v1 != v2)
// 		{
// 			return false;
// 		}
// 	}
// 	return true;
}



void MDString (char *string, unsigned char digest[16])
{
	MD5_CTX context;
	//unsigned char digest[16];
	unsigned int len = strlen (string);

	MD5Init (&context);

	MD5Update (&context, reinterpret_cast<unsigned char *>(string), len);

	MD5Final (digest, &context);


// 	printf ("MD5 (\"%s\") = ", string);
// 	MDPrint (digest);
// 	printf ("\n");
}

bool CompareISOMD5(char *string, const char *expectedresult)
{
	unsigned char digest[16];

	//char calcstring[32];

	char const lookup[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	MDString(string, digest);

	for(int i = 0, j = 0; i < 16; ++i)
	{
		if( expectedresult[j++] != lookup[digest[i] >> 4]
			|| expectedresult[j++] != lookup[digest[i] & 0x0F] )
		//if(digest[i] != expectedresult[i])
		{
			return false;
		}
	}
	return true;
}

bool TestMyMD5()
{
// 	{
// 		bool result = true;
// 
// 		result &= CompareISOMD5(""
// 			, "d41d8cd98f00b204e9800998ecf8427e");
// 
// 		result &= CompareISOMD5("a"
// 			, "0cc175b9c0f1b6a831c399e269772661");
// 
// 		result &= CompareISOMD5("abc"
// 			, "900150983cd24fb0d6963f7d28e17f72");
// 
// 		result &= CompareISOMD5("message digest"
// 			, "f96b697d7cb7938d525a2f31aaf161d0");
// 
// 		result &= CompareISOMD5("abcdefghijklmnopqrstuvwxyz"
// 			, "c3fcd3d76192e4007dfb496cca67e13b");
// 
// 		result &= CompareISOMD5("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
// 			, "d174ab98d277d9f5a5611c2c9f419d9f");
// 
// 		result &= CompareISOMD5("12345678901234567890123456789012345678901234567890123456789012345678901234567890"
// 			, "57edf4a22be3c955ac49da2e2107b67a");
// 
// 		if(!result)
// 		{
// 			int errore = 1;
// 			//return false;
// 		}
// 	}

	{
		bool result = true;

		result &= CompareMyMD5(TMD5("")
			, "d41d8cd98f00b204e9800998ecf8427e");

		result &= CompareMyMD5(TMD5("a")
			, "0cc175b9c0f1b6a831c399e269772661");

		result &= CompareMyMD5(TMD5("abc")
			, "900150983cd24fb0d6963f7d28e17f72");

		result &= CompareMyMD5(TMD5("message digest")
			, "f96b697d7cb7938d525a2f31aaf161d0");

		result &= CompareMyMD5(TMD5("abcdefghijklmnopqrstuvwxyz")
			, "c3fcd3d76192e4007dfb496cca67e13b");

		result &= CompareMyMD5(TMD5("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")
			, "d174ab98d277d9f5a5611c2c9f419d9f");

		result &= CompareMyMD5(TMD5("12345678901234567890123456789012345678901234567890123456789012345678901234567890")
			, "57edf4a22be3c955ac49da2e2107b67a");

		if(!result)
		{
			int errore = 1;
			//return false;
			throw std::exception("Errore Test");
		}
	}

	return true;
}

bool TestMD5()
{
	//TestISOMD5();
	TestMyMD5();

	return true;
}

}
