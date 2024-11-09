double power(double x, int n) {
	if (n == 0) return 1;
	else if (n & 1) return x * power(x * x, (n - 1) / 2);
        else return power(x * x, n / 2);	
}
