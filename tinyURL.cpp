#include <iostream>
#include <map>
#include <random>

using namespace std; 
class Sol {
public:
    map<string, string> urls;
        
    // Encodes a URL to a shortened URL.
     string encode(string longUrl) {
        const static string keys = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

        string key = ""; 
        do{
            key = ""; 
            key += keys[std::rand()%68]; 
            key +=keys[std::rand()%68] ;
            key +=keys[std::rand()%68]  ;
            key +=keys[std::rand()%68] ;
            key +=keys[std::rand()%68] ;
            key +=keys[std::rand()%68];
            
        }while ((urls.find(key) != urls.end()));    
        urls.insert(pair<string ,string>(key, longUrl));
        return "http://tinyUrl.com/" + key; 
        
    }
    // Decodes a shortened URL to its original URL.
   string decode(string shortUrl) {
    string key = shortUrl.substr(shortUrl.size() - 6, 6);
    return urls[key]; 
    }
};
int main(){
    Sol obj; 
    string tiny = obj.encode("http://google.com/khalidali?profile"); 
    cout<<tiny<<endl; 
    cout<<obj.decode(tiny)<<endl;
}