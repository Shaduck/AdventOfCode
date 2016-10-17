
#include "Day_04.h"

#include "Utils/TMD5.h"

#include "Utils/md5.h"


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

void CalcSolution()
{
	//TODO: Controllo prestazioni

	std::string salt("bgvyzdsv");

	bool found = false;

	auto iter = 0u;

	for(; !found; ++iter)
	{
		std::string str = salt + std::to_string(iter);
		TMD5 check(str);

		auto const &result = check.String();

		found = true;
		for(auto i = 0u; found && i < 6; ++i )
		{
			if(result[i] != '0')
			{
				found = false;
			}
		}
	}

	--iter;

	int a = 0;
}





}
