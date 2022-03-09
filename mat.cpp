#include "mat.hpp"
#include <stdexcept>

namespace ariel
{
    void errorThrower(int a, int b, char c1, char c2){
        //aid - https://stackoverflow.com/questions/8480640/how-to-throw-a-c-exception
        if ((a*b) % 2 == 0){
            throw std::invalid_argument( "height and width must be even number" );
        }
        else if(a <= 0 || b<=0){
            throw std::invalid_argument( "height and width must be positive integer");
        }
        else if(c1 <= 32 || c2 <= 32){
            throw std::invalid_argument("invalid ascii");
        }
    }

    std::string mat(int w, int h, char a, char b){
        errorThrower(w,h,a,b);
        //std::string result = "";
        std::string carpet (w*h, a);
        int k = 1;
        while(h-k-1 >=k && w-k-1>=k){
            for(int i = k; i < h-k; i++){
                for(int j = k; j < w-k; j++){
                    carpet[i*w+j] = k % 2 == 0 ? a : b;
                }
            }
            k++;
        }

        std::string result;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                result += carpet[i*w+j];
            }

            if(i < h-1){
                result += '\n';
            }
            
        }
        return result;

    }
} 


