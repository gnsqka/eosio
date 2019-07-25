#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

using namespace eosio;


    CONTRACT onnotify: public contract {

    public:

    using contract::contract;


    ACTION dummy() {}

    [[eosio::on_notify("eosio.token::transfer")]]

    void ontransfer(name from, name to, asset quantity, std::string memo) {

        if(from == get_self()) {

            Receiver receiver(get_self(), get_self().value);

            auto itr = receiver;

            
        if(itr == receiver.end()) {

        receiver.emplace(from, [&](auto& row) {

            row.user = to;

            row.balance = quantity;
            
            row.mykey = receiver.available_primary_key();

            });

        } else {

            receiver.modify(itr, from, [&](auto& row) {

                row.balance += quantity;

            );

            }

        } else if{

            Sender sender(get_self(), get_self().value);

            auto itr = sender;
        
            if(itr == sender.end()) {

        sender.emplace(to, [&](auto& row) {

            row.user = from;

            row.balance = quantity;

            row.mykey = receiver.available_primary_key();

        });

        } else {

            sender.modify(itr, to, [&](auto& row) {

                row.balance += quantity;

            });

        }

        }

    }

        private:

        TABLE trxlist {

        name user;

        asset balance;

        uint64_t mykey;


    uint64_t primary_key() const { return mykey; }

    };


    typedef multi_index<"eossender"_n, trxlist> Sender;

    typedef multi_index<"eosreceiver"_n, trxlist> Receiver;

};

