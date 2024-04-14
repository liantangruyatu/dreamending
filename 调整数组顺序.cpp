void reOrderArray(int *array, int length) {
	int i = 0, j = 0, k = 0;
	int al = 0; //al为奇数数组的空间

	for (i = 0; i < length; i++) {
		if (array[i] % 2 != 0)  //统计奇数数组需要的空间
			al++;
	}
	int bl = length - al;       //bl为偶数数组的空间
	int a[al], b[bl];
	for (i = 0, j = 0; i < length && j < al ; i++) {
		if (array[i] % 2 == 1)     //得到奇数数组
			a[j++] = array[i];
	}
	for (i = 0, k = 0; i < length && k < bl ; i++) {
		if (array[i] % 2 == 0)
			b[k++] = array[i];          //得到偶数数组
	}
	for (i = 0, j = 0; i < length; i++)
		array[i] = a[j++];
	for (i = al, k = 0; i < length; i++)
		array[i] = b[k++];
}