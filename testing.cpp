#include "Decryption.h"
#include <iostream>
using namespace std;
int main()
{
    CaesarCipher caesarCipher;
    //string line = "Rather than requiring all desired functionality be built into the language's core,";
    
    //caesarCipher.character_count(line);
    //caesarCipher.print_analysis_array();
    //int m_index = caesarCipher.max_index();

    //string line = "Yhaoly aohu ylxbpypun hss klzpylk mbujapvuhspaf il ibpsa puav aol shunbhnl'z jvyl,";
    //string decrypted_text = caesarCipher.decrypt(line,7);

    //cout<< "max index = "<<m_index;
    //cout<< "decrypted text = "<<decrypted_text;

    cout<<caesarCipher.to_upper('t')<<endl;
    cout<<caesarCipher.is_alpha(',')<<endl;
    cout<<caesarCipher.is_upper('U')<<endl;


    return 0;


}
