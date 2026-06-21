#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <span>
#include <memory>

namespace nanograph {
    using NodeID = uint64_t;

    struct SearchResult {
        NodeID id;
        float similarity_score; // 1.0 is a perfect match, 0.0 is completely different
        std::string metadata; // text/JSON stored in the node
    };
    
    class Database {
    public: 
        explicit Database(const std::string& file_path, size_t vector_dimension = 384);
        ~Database(); 
        
        // 1. write api 
        NodeID insert_node(std::span<const float> embedding, const std::string& metadata);
        bool add_edge(NodeID source, NodeID target);

        // 2. read api
        std::vector<SearchResult> vector_search(std::span<const float> query_embedding, int top_k = 5) const;
        std::vector<NodeID> get_neighbors(NodeID start_node, int max_depth = 1) const;

        std::vector<SearchResult> hybrid_search(
            std::span<const float> query_embedding, 
            NodeID start_node, 
            int max_hops, 
            int top_k = 5
        ) const;
    private: 
        //pointer to implementation
        struct Impl; 
        std::unique_ptr<Impl> pImpl_;
    };
}