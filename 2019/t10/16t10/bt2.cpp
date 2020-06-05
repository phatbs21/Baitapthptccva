#include <bits\stdc++.h>
using namespace std;

#include <atlenc.h>
int ToBase64ATL( const BYTE* pSrc, int nLenSrc, char* pDst, int nLenDst )
{
   int nDestLen= nLenDst;
   BOOL fRet= Base64Encode( pSrc, nLenSrc, pDst, &nDestLen,  ATL_BASE64_FLAG_NOCRLF );
   if (!fRet) nDestLen=0;
   return( nDestLen );
}
int FromBase64ATL( const BYTE* pSrc, int nLenSrc, char* pDst, int nLenDst )
{
   int nDestLen= nLenDst;
   BOOL fRet= Base64Decode( (LPCSTR)pSrc, nLenSrc, (BYTE*)pDst, &nDestLen );
   if (!fRet) nDestLen=0;
   return( nDestLen );
}
int main()
{
    string s;
    int n = s.length();
    if (n % 3 != 0)
        s.insert(n, "0");
    if (n % 3 == 1)
        s.insert(n, "0");
    int m;
    for (int i = 0; i <= (n + 3) / 3; i++)
    {
        m = s[3*i] * 256 * 256 + s[3*i + 1] * 256 + s[3*i + 2];
        m=base64Encoder(m,);
    }
}
