#include <eosiolib/eosio.hpp>

using namespace eosio;

CONTRACT helloworld : public contract {

    public:
        using contract::contract;
        

        ACTION hi(name user) {

            check(has_auth( get_self() ) || has_auth("pppppppppppp"_n), "you sexy boy");
            

           // check(has_auth( get_self() ), "SIBABABAL"); //자신의 계정만

            //require_auth(user); //권한 검사
            
            //
            print("hello, ",user);
        }
 
        ACTION getaccount(name user) {
            require_auth(get_self() );

            print( is_account(user) );
        }
    private:

};