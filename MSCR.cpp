#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include<vector> 
using namespace std;
#define max 100
int	d = 0;
string	val[max * max];
int	g = 0;
string	w;
int	y = 0;
struct strin {
	string	a;
	string	name;
};
struct num {
	int	a;
	string	name;
};
struct num	swsex[max];
struct strin	strex[max];
int		ggex	= 0;
int		sgex	= 0;
int		bggex	= 0;
string tot( int &h, string com ) {
	string b;
	for (; com[h] != '\"'; h++ )b=b+com[h];
	return(b);
}


int totr( int h ) {
	for (;; h++ ) {
		for ( int i = 0;; i++ ) {
			if ( val[h][i] == '\"' )
				return(h);
		}
	}
	return(h);
}

std::string ws(const std::wstring& ws)
{
    std::string strLocale = setlocale(LC_ALL, "");
    const wchar_t* wchSrc = ws.c_str();
    size_t nDestSize = wcstombs(NULL, wchSrc, 0) + 1;
    char *chDest = new char[nDestSize];
    memset(chDest,0,nDestSize);
    wcstombs(chDest,wchSrc,nDestSize);
    std::string strResult = chDest;
    delete []chDest;
    setlocale(LC_ALL, strLocale.c_str());
    return strResult;
}
// string => wstring
std::wstring sw(const std::string& s)
{
    std::string strLocale = setlocale(LC_ALL, "");
    const char* chSrc = s.c_str();
    size_t nDestSize = mbstowcs(NULL, chSrc, 0) + 1;
    wchar_t* wchDest = new wchar_t[nDestSize];
    wmemset(wchDest, 0, nDestSize);
    mbstowcs(wchDest,chSrc,nDestSize);
    std::wstring wstrResult = wchDest;
    delete []wchDest;
    setlocale(LC_ALL, strLocale.c_str());
    return wstrResult;
}
int sfws( char *path, const char *in ) {
	FILE *fp;
	fp = fopen( path, "w" );
	fprintf( fp, "%s", in );
	fclose( fp );
}
std::vector<int> stringToVecInt(const std::string &str)
{
    union {
        char c[2];
        int  i;
    } convert;

    // 段位清零
    convert.i = 0;

    std::vector<int> vec;

    for (unsigned i = 0; i < str.length(); i++) {
        // GBK编码首字符大于0x80
        if ((unsigned)str[i] > 0x80) {
            // 利用union进行转化，注意是大端序
            convert.c[1] = str[i];
            convert.c[0] = str[i + 1];
            vec.push_back(convert.i);
            i++;
        } else
            // 小于0x80，为ASCII编码，一个字节
            vec.push_back(str[i]);
    }
    return vec;
}
void rununtilwn( string s, int &y ) {
	for (; val[y] != s; y++ ) {
	}
}

void run(string);
int create( int i ) {
	if ( val[i] == "按钮" ) {
		w += "button\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n";
		return(i);
	} else if ( val[i] == "文本框" ) {
		w += "textbox\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n";
		return(i);
	} else if ( val[i] == "标签" ) {
		w += "label\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n";
		return(i);
	} else if ( val[i] == "窗体" ) {
		w += "form\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n" + val[++i] + "\n";
		return(i);
	} else if ( val[i] == "redraw" ) {
		remove( "out.u" );
		w = "";
		return(i);
	} else {
		cout << "creatig window error:" << i << "(" + val[i] + "):error point" << endl;
		return(i);
	}
}


int numof( string d ) {
	int	q	= 0;
	int	p	= 1;
	for ( int i = 0; d[i] != '\0'; i++, p *= 10 ) {
		q += (d[i] - '0') * p;
	}
	return(q);
}


int findint( string name ) {
	for ( int u = 0; u < ggex; u++ ) {
		if ( swsex[u].name == name ) {
			return(swsex[u].a);
		}
	}
	return(0);
}


int valof( int &d ) {
	int v = 0;
	if ( val[d] == "(" ) {
		d++;
		v = numof( val[d] );
		d++;
		for (; val[d] != ")"; ) {
			if ( val[d] == "+" ) {
				v += numof( val[++d] );
				d++;
			}
			if ( val[d] == "+" ) {
				v -= numof( val[++d] );
				d++;
			}
			if ( val[d] == "+" ) {
				v *= numof( val[++d] );
				d++;
			}
			if ( val[d] == "+" ) {
				v /= numof( val[++d] );
				d++;
			}
			if ( val[d] == "+" ) {
				v %= numof( val[++d] );
				d++;
			}
		}
		return(v);
	} else if ( val[d][0] >= '0' && val[d][0] <= '9' ) {
		return(numof( val[d] ) );
	} else {
		return(findint( val[d] ) );
	}
}


void sfrs( string tt ) {
	string		com;
	ifstream	myfile( tt.c_str() );
	string		temp;
	if ( !myfile.is_open() ) {
		cout << "邵帝未成功打开文件" << endl;
		exit( 0 );
	}
	while ( getline( myfile, temp ) ) {
		com	+= temp;
		com	+= " ";
	}
	myfile.close();
	temp = "";
	for ( int i = 0; com[i] != '\0'; i++ )
		if ( com[i] == ' '||  com[i] == '{' || com[i] == '}' || com[i] == '\n' || com[i] == '{' || com[i] == '(' || com[i] == ')' )
			y++;
	for ( int r = 0; com[r] != '\0'; r++ ) {
		if ( com[r] == '\"' ) {
			tot( r, com );
		}
		if ( com[r] == ' ' || com[r] == '\n') {
			if ( temp != "" ) {
				//cout<<temp<<endl;
				if(temp.find("\"",0)>=temp.length()){
				if(temp.find("函数",0)<temp.length())temp="函数";//,cout<<"ok";
				if(temp.find("全局变量",0)<temp.length())temp="全局变量";//,cout<<"ok";
				if(temp.find("数字",0)<temp.length())temp="数字";
				if(temp.find("为",0)<temp.length())temp="=";
				if(temp.find("等于",0)<temp.length())temp="==";
				if(temp.find("加",0)<temp.length())temp="+";
				if(temp.find("减",0)<temp.length())temp="-";
				if(temp.find("乘",0)<temp.length())temp="*";
				if(temp.find("除",0)<temp.length())temp="/";
				}
				val[g] = temp;
				g++;
				temp = "";
			}
		} else {
			temp += com[r];
		}
	}
	return;
}


void cr( string name ) {
	for ( int i = 0; i < g; i++ ) {
		if ( val[i] == "创建" && val[i + 1] == name ) {
			for ( int u = i + 2; val[u] != "结束"; u++ ) {
				u = create( u );
			}
			sfws( "out.u", w.c_str() );
			system( "GUI.exe" );
		}
	}
}



bool returnb( int &i, int u ) {
	if ( val[i] == "(" )
		u++;
	for (; val[u] != ")"; u++ ) {
		if ( val[u + 1] == "<" ) {
			if ( valof( u ) < valof( u += 2 ) )
				i=u;
			return(true);
		}
		if ( val[u + 1] == ">" ) {
			if ( valof( u ) > valof( u += 2 ) )
				i=u;
			return(true);
		}
		if ( val[u + 1] == "==" ) {
			if ( valof( u ) == valof( u += 2 ) )
				i=u;
			return(true);
		}
		if ( val[u + 1] == "!=" ) {
			if ( valof( u ) != valof( u += 2 ) )
				i=u;
			return(true);
		}
	}
	i = u;
	return(false);
}
void skipuntil(string a,int &j) {
	while(val[++j]!=a);
	return ;
}
int yj;
int &j=yj;
bool ij=false;
string s;

void *isevent( void* ) {
	string h[max];
	for (;; Sleep( 300 ) ) {
		int		y = 0;
		ifstream	myfile( "event.vo" );
		string		temp;
		if ( myfile.is_open() ) {
			while ( getline( myfile, h[y] ) ) {
				y++;
			}
		}
		myfile.close();
		remove( "event.vo" );
	}
}

void run( string name ) {
	struct num	sws[max];
	struct strin	str[max];
	int		gg	= 0;
	int		sg	= 0;
	int		bgg	= 0;
	if ( name == "创建" ) {
		for ( int i = 0; i < g; i++ ) {
			if ( val[i] == "创建" ) {
				for ( int u = i + 1; val[u] != "结束"; u++ ) {
					u = create( u );
				}
				sfws( "out.u", w.c_str() );
				system( "GUI.exe" );
			}
		}
	} else {
		bool txz=false;
		for ( int jj = 1; ; jj++ ) {

                if(ij==false){
                    if(jj >= g)return;
                    j=jj;
                }else{
                	if(val[jj]=="{"){
                		txz=true;
                		j=jj;
					}
                   if(val[j] == s){
                        ij=false;
                        return;
                   }

                }
			if ( (val[j - 1] == "函数" && val[j] == name )||txz) {
				for ( int i = j + 1; val[i] != "返回"; i++ ) {
					if(txz){
						if(val[i]==s)return;
					}
					if ( val[i] == "}" )
						continue;
					if ( val[i] == "{" )
						continue;
					for ( int y = 0; val[i][y] != '\0'; y++ ) {
						if ( val[i][y] == '\"' ) {
							i = totr( i );
							cout << "ok";
							system( "pause" );
						}
					}
					if ( val[i] == "数字" ) {
						for ( int ji = 0; ji < gg; ji++ ) {
							if ( sws[ji].name == val[i] ) {
								cout << "error in word (" + val[i] + "),redim of the int.";
								return;
							}
						}
						i++;
						sws[gg].a	= 0;
						sws[gg].name	= val[i];
						gg++;
						if ( gg > sg ) {
							bgg = gg;
						} else {
							bgg = sg;
						}
					} else if ( val[i] == "字符串" ) {
						for ( int ji = 0; ji < sg; ji++ ) {
							if ( str[ji].name == val[i] ) {
								cout << "error in word (" + val[i] + "),redim of the string.";
								return;
							}
						}
						i++;
						str[sg].a	= "";
						str[sg].name	= val[i];
						sg++;
						if ( gg > sg ) {
							bgg = gg;
						} else {
							bgg = sg;
						}
					} else if ( val[i] == "运行" ) {
						run( val[++i]);
					} else if ( val[i] == "全局变量" ) {
						i++;
						for ( int ji = 0; ji < ggex; ji++ ) {
							if ( swsex[ji].name == val[i] ) {
								cout << "error in word (" + val[i] + "),redim of the int.";
								return;
							}
						}
						swsex[ggex].a		= 0;
						swsex[ggex].name	= val[i];
						ggex++;
						if ( ggex > sgex ) {
							bggex = ggex;
						} else {
							bggex = sgex;
						}
					} else if ( val[i] == "全局字符串" ) {
						i++;
						for ( int ji = 0; ji < sgex; ji++ ) {
							if ( strex[ji].name == val[i] ) {
								cout << "error in word (" + val[i] + "),redim of the string.";
								return;
							}
						}
						strex[sgex].a		= "";
						strex[sgex].name	= val[i];
						sgex++;
						if ( ggex > sgex ) {
							bggex = ggex;
						} else {
							bggex = sgex;
						}
					} else if ( val[i + 1] == "=" ) {
						int uuu = 0;
						if ( val[i + 2][0] == '\"' ) { /*  */
							for ( int ie = 0; ie < sg; ie++ ) {
								if ( str[ie].name == val[i] ) {
									uuu		= ie;
									str[uuu].a	= "";
								}
							}
							for ( int h = 1; val[i + 2][h] != '\"'; h++ ) {
								str[uuu].a += val[i + 2][h];
							}
							if ( uuu == 0 ) {
								for ( int ie = 0; ie < sgex; ie++ ) {
									if ( strex[ie].name == val[i] ) {
										uuu		= ie;
										strex[uuu].a	= "";
									}
								}
								for ( int h = 1; val[i + 2][h] != '\"'; h++ ) {
									strex[uuu].a += val[i + 2][h];
								}
							}
						} else {
							bool d = false;
							for ( int u = 0; u < gg; u++ ) {
								if ( sws[u].name == val[i] ) {
									i		+= 2;
									sws[u].a	= valof( i ); /* atoi(val[i+2].c_str()); */
									d		= true;
								}
							}
							if ( d == false ) {
								for ( int u = 0; u < ggex; u++ ) {
									if ( swsex[u].name == val[i] ) {
										i		+= 2;
										swsex[u].a	= valof( i ); /* atoi(val[i+2].c_str()); */
									}
								}
							}
						}
					} else if ( val[i] == "+=" ) {
						i=i-1;
						int uuu = 0;
						if ( val[i + 2][0] == '\"' ) { /*  */
							for ( int ie = 0; ie < sg; ie++ ) {
								if ( str[ie].name == val[i] ) {
									uuu = ie;
								}
							}
							for ( int h = 1; val[i + 2][h] != '\"'; h++ ) {
								str[uuu].a += val[i + 2][h];
							}
						} else {
							for ( int u = 0; u < gg; u++ ) {
								if ( sws[u].name == val[i] ) {
									i += 2;
									sws[u].a + valof( i ); /* atoi(val[i+2].c_str()); */
								}
							}
						}
					}else if ( val[i + 1] == "+=" ) {
						int uuu = 0;
						if ( val[i + 2][0] == '\"' ) { /*  */
							for ( int ie = 0; ie < sg; ie++ ) {
								if ( str[ie].name == val[i] ) {
									uuu = ie;
								}
							}
							for ( int h = 1; val[i + 2][h] != '\"'; h++ ) {
								str[uuu].a += val[i + 2][h];
							}
						} else {
							for ( int u = 0; u < gg; u++ ) {
								if ( sws[u].name == val[i] ) {
									i += 2;
									sws[u].a + valof( i ); /* atoi(val[i+2].c_str()); */
								}
							}
						}
					} else if ( val[i + 1] == "-=" ) {
						int uuu = 0;
						for ( int u = 0; u < gg; u++ ) {
							if ( sws[u].name == val[i] ) {
								i		+= 2;
								sws[u].a	-= valof( i ); /* atoi(val[i+2].c_str()); */
							}
						}
					} else if ( val[i + 1] == "*=" ) {
						int uuu = 0;
						for ( int u = 0; u < gg; u++ ) {
							if ( sws[u].name == val[i] ) {
								i		+= 2;
								sws[u].a	*= valof( i ); /* atoi(val[i+2].c_str()); */
							}
						}
					} else if ( val[i + 1] == "/=" ) {
						int uuu = 0;
						for ( int u = 0; u < gg; u++ ) {
							if ( sws[u].name == val[i] ) {
								i		+= 2;
								sws[u].a	/= valof( i ); /* atoi(val[i+2].c_str()); */
							}
						}
					} else if ( val[i] == "创建图形界面" ) {
						i++;
						cr( val[i] );
					} else if ( val[i] == "如果" ) {
				i++;
				if ( returnb( i, i ) != true ) {
					skipuntil( "}", i );
				}else{

					skipuntil( "{", i );
				}
					} else if ( val[i] == "循环" ) {
						i++;
						for (; returnb( i, i ) != true; ) {
							int u = i;
							rununtilwn( "{", u );
							ij=true;
							j=u;
							j++;
							s="}";
							run("");
						}
						rununtilwn( "}", i );
						i--;
					}  else if ( val[i] == "坚持住！" ) {
						getchar();
					} else if ( val[i] == "输出" ) {
						i++;
						for (; val[i] != ";"; i++ ) {
							if ( val[i] == "," ) {
								continue;
							} else if ( val[i][0] != '\"' ) {
								bool aa = true;
								for ( int ii = 0; ii < max; ii++ ) {
									if ( str[ii].name == val[i] ) {
										aa = false;
										break;
									} else if ( sws[ii].name == val[i] ) {
										aa = false;
										break;
									}
								}
								for ( int ii = 0; ii < max; ii++ ) {
									if ( strex[ii].name == val[i] ) {
										aa = false;
										break;
									} else if ( swsex[ii].name == val[i] ) {
										aa = false;
										break;
									}
								}
								if ( aa == true && val[i] != "(" ) {
									cout << "error in word " << i << "(" << val[i] << ")" << ":string(or int) was no be found." << endl;
									i++;
								} else cout << valof( i );
							} else {
								for ( int y = 1; val[i][y] != '\"'; y++ ) {
									if ( val[i][y] == '\0' )i++, y = 0;
									if(val[i][y]=='\\') {
										if(val[i][y+1]== 'n') {
											y++;
											putchar('\n');
											break;
										} else if(val[i][y+1]== 'c') {
											y++;
											system("cls");
											break;
										} else if(val[i][y+1]== 'b') {
											y++;
											putchar('\b');
											break;
										} else if(val[i][y+1]== '\\') {
											y++;
											putchar('\\');
											break;
										} else if(val[i][y+1]== 'b') {
											y++;
											putchar('\b');
											break;
										} else {
											cout<<"in string ("+val[i]+") word used failed";
											break;
										}
									} else {
										putchar( val[i][y] );
									}
								}
							}
						}
						gg++;
					} else if ( val[i] == "输入" ) {
						i++;
						for (; val[i] != ";"; i++ ) {
							if ( val[i] == "," ) {
								continue;
							} else if ( val[i][0] != '\"' ) {
								bool aa = true;
								for ( int ii = 0; ii < max; ii++ ) {
									if ( str[ii].name == val[i] ) {
										cin >> str[ii].a;
										aa = false;
										continue;
									} else if ( sws[ii].name == val[i] ) {
										cin >> sws[ii].a;
										aa = false;
										continue;
									}
								}
								for ( int ii = 0; ii < max; ii++ ) {
									if ( strex[ii].name == val[i] ) {
										cin >> strex[ii].a;
										aa = false;
										continue;
									} else if ( swsex[ii].name == val[i] ) {
										cin >> swsex[ii].a;
										aa = false;
										continue;
									}
								}
								if ( aa == true &&val[i]!="}"&&val[i]!="{")
									cout << "error in word " << i << "(" << val[i] << ")" << ":string(or int) was no be found." << endl;
							}
						}
						gg++;
					} else if(val[i]!="}"&&val[i]!="{") {
						cout << "error in word " << i << "(" << val[i] << ")" << ":word with no mean" << endl;
					}
				}
			}
		}
	}
}


void clean( void ) {
	remove( "event.vo" );
	/* remove("out.u"); */
}


void* tr1( void* ) {
	run( "create" );
	run( "main" );
	clean();
	exit( 0 );
}


int main( int argc, char *argv[10] ) {
	if(argc<=1) {
		cout<<"您正在运行邵帝开发的MSCR软件，请在命令行中指定您需要运行的程序！\n用法：[exe] [程序路径]\n输入r运行示例程序，按回车以退出:";
	
		if(getchar()=='r')argv[1] = "example.alp";
		else return 0;
	} 
	sfrs( argv[1] );
	pthread_t	ttt;
	pthread_t	pdd;
	pthread_create( &ttt, NULL, tr1, NULL );
	pthread_create( &pdd, NULL, isevent, NULL );
	pthread_exit( NULL );
}
