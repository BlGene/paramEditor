#include "/home/hasimir/lang/treetree-read-only/foreach.hpp"
#include "/home/hasimir/lang/treetree-read-only/tree_io.hpp"
#include "/home/hasimir/lang/treetree-read-only/tree_iterator.hpp"

using namespace std;
using namespace boost;
using namespace TREE_TREE_NAMESPACE;

typedef tree<int> itree;

int main()
{

    itree tr;

    tr.insert(tr.end(),1);

    tr.insert(tr.end_child(),2);
    tr.insert(tr.end_child(),3);

    tr.insert(tr.begin_sub_child()->begin_child(),4);

    tr.insert(tr.end_child(),tree_of(5)(2,3));
    tr.insert(tr.begin_sub_child()->begin_child(),6);

    tr.append(1,tree_of(1)(2,3));
    //tr.insert_below(tr.end_child(),8);

    cout << tr << endl;

    //          1
    //        / | \
    //       2  3  5
    //      / \
    //     6   4
}
