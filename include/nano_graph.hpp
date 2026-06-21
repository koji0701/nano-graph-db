#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <span>

namespace nanograph {
    using NodeID = uint64_t;

    struct SearchResult {
        NodeID id;
        float similarity_score; // 1.0 is a perfect match, 0.0 is completely different
        std::string metadata;   //text/JSON stored in the node
    };
    
    

}