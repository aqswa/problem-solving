int main(){
    int list[N];
    srand(time(NULL));
    for(int i=0; i<N; i++)
        list[i] = rand()%999+1;

    for(int i=0; i<N; i++)
        printf("%d ", list[i]);
    printf("\n");

    radixSort(list);

    for(int i=0; i<N; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}