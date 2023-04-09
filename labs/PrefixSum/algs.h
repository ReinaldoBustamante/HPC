// Prefix Sum secuencial
void psums_seq(int *x,int *s,int n){
    if(n == 0){ return; }
    s[0] = x[0];
	for (int i = 1; i < n; ++i){
		s[i]=s[i-1] + x[i];
	}
}

// (1) Prefix Sum recursivo
void psums_rec(int *x,int *s,int n, int nt){
	int blocksize = n/nt;
	printf("FALTA ESTO");
}

// (2) Prefix Sum iterativo
void psums_it(int *x,int *s,int n, int nt){
	int blocksize = n/nt;
	printf("\nEl arreglo se dividira en %i segmentos de %i valores\n\n",nt,blocksize);
	#pragma omp parallel
	{
		//Fase 1 ---- Inicializar valores de inicio para cada thread.
		int tid = omp_get_thread_num(); // thread de turno
		int segment = tid*blocksize; // [1,2,3,4,5,6,7,8], nt = 2, segmento(tid=0) = 0, segmento(tid=1) = 4
		int suma = 0; 
		for(int i = 0; i < segment+1 ; i++){ // [1,2,3,4,5,6,7,8], suma(segmento0) = 1 , suma(segmento1) = 15 
			suma += x[i];
		}
		s[segment] = suma; // s[] = [1,0,0,0,15,0,0,0]
		//printf("Hilo: %i trabajara en el segmento de inicio, %i, cuyo valor es %i\n\n",tid,segment,suma);
		#pragma omp barrier
		//Fase 2 ---- Realizar prefixSum para cada bloque
		for(int i = segment ; i<segment+blocksize ; i++){
			s[i+1] = s[i]+x[i+1]; // s[] = [1,3,6,10,15,21,28,36]
		}
		
	}

}
