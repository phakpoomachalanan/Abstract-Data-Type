while (max_heap->tree[2].data != 0) {
    left = delete_min1(max_heap);
    printf("de1");
    bfs(max_heap);
    right = delete_min1(max_heap);
    printf("de2");
    bfs(max_heap);
    add_tree(max_heap, left, right);
    printf("add");
    bfs(max_heap);
  }