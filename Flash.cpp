#include <iostream>
#include <unistd.h>  // for sleep function
using namespace std;

void change();

int main(){
    int sec,t;
    system("clear");
    system("echo  \" \033[01m \033[34m \" ");
    system("figlet   \"Flash Ip Changer\" ");

    cout<<"\033[01m\033[34m\n[*] Current ip address:"<<endl;
    system("curl myexternalip.com/raw");
    cout<<"\033[34m\n\nIn order to use this tool change your  SOCKES to \033[33m127.0.0.1:9050 "<<endl;
    system("service tor start");
    cout<<"\033[34m\n\a[*] Enter the time to change Ip in Sec\n\033[94m  >> ";
    cin>>sec;
    cout<<"\033[34m\a[*] Enter how many times you want the task to repeat \033[33m(type 0 for infinite)\n\033[94m  >>";
    cin>>t;
    cout<<"\n\n";

    if(t ==0){
        for(; ;){
            try{
                sleep(sec);
                change();
            }
            catch(...){
                cout<<"\nAuto tor is closing ....."<<endl;
                exit(1);
            }
        }
    }
    else{
        for(int i=0;i<t;i++){
            sleep(sec);
            change();
	    cout<<endl;
        }
    }


}

void change(){
    system("service tor reload");
    system("curl --preproxy socks5://127.0.0.1:9050  \"https://www.myexternalip.com/raw\"");
	cout<<endl;

}
