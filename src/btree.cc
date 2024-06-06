#include "db/bpt.h"
#include "db/block.h"
#include "db/table.h"
#include "db/buffer.h"
#include <stdlib.h>

#include <list>
#include <algorithm>
#include <queue>
using std::swap;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;

namespace db {

void btree::clear_tree(unsigned int root) {
	int indexroot=root;
    std::queue<unsigned int> index_blocks;//用于寻找所有节点
    std::queue<unsigned int> index_record;//记录所有节点
    index_blocks.push(indexroot);
    index_record.push(indexroot);
    while (!index_blocks.empty()) {
        IndexBlock index;
        unsigned int now = index_blocks.front();
        index_blocks.pop();
        BufDesp *desp = kBuffer.borrow(table_->name_.c_str(), now);
        index.attach(desp->buffer);
        index.setTable(table_);
        for (unsgined short i = 0; i < index.getSlots(); ++i) {
            Slot *slot = index.getSlotsPointer() + i;
            Record record;
            record.attach(
                index.buffer_ + be16toh(slot->offset), be16toh(slot->length));
            unsigned char *pkey;
            unsigned int len;
            long long key;
            record.refByIndex(&pkey, &len, 0);
            memcpy(&key, pkey, len);
            key = be64toh(key);

            unsigned char *pavlue;
            unsigned int value;
            unsigued int value_len;


        }
    }
}
void btree::index_creat(IndexBlock) {

}

void btree::insert(void* key, size_t key_len, unsigned int newblockid) {

}

unsigned int btree::search(void* key, size_t key_len) {

}

std::pair<bool, unsigned int> btree::index_search(void* key, size_t key_len) {

}

int btree::remove(void* key, size_t key_len) {

}





}