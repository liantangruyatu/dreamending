void reOrderArray(int *array, int length) {
	int i = 0, j = 0, k = 0;
	int al = 0; //alΪ��������Ŀռ�

	for (i = 0; i < length; i++) {
		if (array[i] % 2 != 0)  //ͳ������������Ҫ�Ŀռ�
			al++;
	}
	int bl = length - al;       //blΪż������Ŀռ�
	int a[al], b[bl];
	for (i = 0, j = 0; i < length && j < al ; i++) {
		if (array[i] % 2 == 1)     //�õ���������
			a[j++] = array[i];
	}
	for (i = 0, k = 0; i < length && k < bl ; i++) {
		if (array[i] % 2 == 0)
			b[k++] = array[i];          //�õ�ż������
	}
	for (i = 0, j = 0; i < length; i++)
		array[i] = a[j++];
	for (i = al, k = 0; i < length; i++)
		array[i] = b[k++];
}