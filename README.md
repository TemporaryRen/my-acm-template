# my-acm-template
template of some algorithm
## vscode snippets
|prefix|description|
|-|-|
|acmz|common template|
|kmp search|kmp search|
|pi_fun|prefix array function|
```json
{
	// Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and 
	// description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
	// same ids are connected.
	// Example:
	// "Print to console": {
	// 	"prefix": "log",
	// 	"body": [
	// 		"console.log('$1');",
	// 		"$2"
	// 	],
	// 	"description": "Log output to console"
	// }
	"acm contest template":{
		"prefix": ["acmz"],
		"body": [
			"#include <bits/stdc++.h>",
			"using namespace std;","#define ll long long\n",
			"void solve(){",
			"}",
			"\n",
			"int main() {",
			"\tios_base::sync_with_stdio(false);",
			"\tcin.tie(nullptr);",
			"\tcout.tie(nullptr);",
			"\tint tc = 1;",
			"\tcin >> tc;",
			"\tfor (int t = 1; t <= tc; t++) {",
			"\t\tsolve();",
			"\t}",
			"\treturn 0;",
			"}"
	],
		"description": "acm contest template"
	},
	"string prefix array function":{
		"prefix": ["pi_fun"],
		"body": [
			"vector<int> pi_fun(string s) {",
			"\tint n = s.size();",
			"\tvector pi(n,0);",
			"\tfor (int i = 1; i < n; i++) {",
			"\t\tint j = pi[i - 1];",
			"\t\twhile (j > 0 && s[i] != s[j])j = pi[j - 1];",
			"\t\tif (s[i] == s[j]) ++j;",
			"\t\tpi[i] = j;",
			"\t}",
			"\treturn pi;",
			"}"

		],
		"description": "string prefix array function"
	},
	"kmp search":{
		"prefix": ["kmp_fun"],
		"body": [
			"vector<int> pi_fun(string s) {",
			"\tint n = s.size();",
			"\tvector pi(n,0);",
			"\tfor (int i = 1; i < n; i++) {",
			"\t\tint j = pi[i - 1];",
			"\t\twhile (j > 0 && s[i] != s[j])j = pi[j - 1];",
			"\t\tif (s[i] == s[j]) ++j;",
			"\t\tpi[i] = j;",
			"\t}",
			"\treturn pi;",
			"}",
			"\n",
			"void kmp(string s,string t){",
			"\tauto pi = pi_fun(t);",
			"\tint n = s.size();",
			"\tint m = t.size();",
			"\tint j = 0;",
			"\tfor(int i=0;i<n;i++){",
			"\t\tchar c = s[i];",
			"\t\twhile(j>0 && c!=t[j]) j = pi[j-1];",
			"\t\tj += (c==t[j]);",
			"\t\tif(j==m){",
			"\t\t\t//match success and do something",
			"\t\t}",
			"\t}",
			"}"
		],
	}
}
```
