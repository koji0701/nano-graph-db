NanoGraph is an embedded vector-graph database written in modern C++23. 

File Directory

```
nanograph/
├── include/
│   └── nanograph.hpp      # Public API interface
├── src/
│   ├── storage_engine.cpp # mmap wrapper & Arena allocator
│   ├── vector_index.cpp   # HNSW logic & SIMD distance formulas
│   └── graph_engine.cpp   # Graph traversal & Filtering
├── tests/
│   └── test_queries.cpp
├── CMakeLists.txt
```