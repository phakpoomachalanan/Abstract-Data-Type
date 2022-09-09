static bst_t *parent = NULL;
  if (v < t->data) {
      parent = t;
      find_parent(t->left, v);
  } else if (v > t->data) {
      parent = t;
      find_parent(t->right, v);
  } else if (t->data == v) {
      return parent;
  } 