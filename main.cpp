#include <iostream>
#include <functional>

// Types
#include "Maybe.type"

// Type Classes
#include "Monad.class"


auto add2 = std::function([](int x)->int{
                return x + 2;
                });

int main(void){
        auto mx = Maybe(3);
        auto my = Monad::liftM(add2, mx);

        auto empty = Maybe<int>();
        auto empty2 = Monad::liftM(add2, empty);

        std::cout << my.exists() << " " << my.extract() << std::endl;
        std::cout << empty.exists() << " " << empty2.exists() << std::endl;
        

        return 0;
}
