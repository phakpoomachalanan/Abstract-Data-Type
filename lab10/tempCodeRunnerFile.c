int i = 1;
  while ((max_heap->data[i*2] != 0 || max_heap->data[(i*2)+1] != 0) && i*2 <= max_heap->last_index) {
    if (max_heap->data[i*2]>max_heap->data[i]) {
      max_heap->data[i] = max_heap->data[i*2];
      max_heap->data[i*2] = data;
      i = i*2;
    } else if (max_heap->data[(i*2)+1]>max_heap->data[i]) {
      max_heap->data[i] = max_heap->data[(i*2)+1];
      max_heap->data[(i*2)+1] = data;
      i = (i*2)+1;
    } else {
      i++;
    }
  }