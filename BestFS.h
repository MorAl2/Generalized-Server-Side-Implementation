//
// Created by noy on 13/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_BESTFS_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_BESTFS_H

#include "SearcherAbstract.h"
#include <bits/stdc++.h>
#include "list"
template <typename T>
class BestFS: public SearcherAbstract<T> {
// TODO - create back trace through parents
int backTrace(){
return 1;
}
public:
    Solution search(Searchable<T> searchable) {
         this->getOpenList()->push(searchable.getInitialState());
         unordered_set <State<T>> *closed = new unordered_set <State<T>>;
         while(this->openListSize()>0){
             State<T> n = this->popOpenList();
             closed->insert(n);
             if(searchable.isGoalState(n)){
                 return backTrace();
             }
             list<State<T>> succerssors = searchable.getAllPossibleStates(n);
             for (State<T> s : succerssors)
             {
                 if((!(closed->find(s)!=closed->end()))&&(!(this->openContains(s)))){
                     s.setCameFrom(n);
                     s.setSumState(s.getCost()+n.getSumState());
                     addToOpenList(s);
                 // 5.b
                 } else {
                     if((s.getCost()+n.getSumState())<(s.getSumState())){
                         // 5.b.i
                         if(!this->openContains(s)){
                             this->addToOpenList(s);
                             closed->erase(closed->find(s));
                         // 5.b.ii
                         } else {
                            s.setSumState(s.getCost()+n.getSumState());
                            s.setCameFrom(n);
                         }
                     }
                 }
             }
         }
    }


};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_BESTFS_H
