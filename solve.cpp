// IntelliVision Aptitude Test

bool is_inside(double v1x, double v1y,
	double v2x, double v2y,
	double v3x, double v3y,
	double px, double py)
{
	double det = 0.0;
	//(a,b,c) - барицентрические координаты
	//a+b+c=1
	//a*v1x+b*v2x+c*v3x=px
	//a*v1y+b*v2y+c*v3y=py
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	det = v2x*v3y + v1x*v2y + v1y*v3x - v1y*v2x - v2y*v3x - v1x*v3y;
	a = (v2x*v3y + px*v2y + py*v3x - py*v2x - v2y*v3x - px*v3y) / det;
	b = (px*v3y + v1x*py + v1y*v3x - v1y*px - py*v3x - v1x*v3y) / det;
	c = (v2x*py + v1x*v2y + v1y*px - v1y*v2x - v2y*px - v1x*py) / det;
	if (a > 0 && b > 0 && c > 0) return true;
	else return false;
}

unsigned char median(const unsigned char arr[], int N)
{
	unsigned char med = 0;
	int chet = N;
	bool odd = true;
	if (N % 2 == 0.0) odd = false;
	int size_fr = pow(sizeof(unsigned char) * 8, 2);
	unsigned char *frequency = new unsigned char[size_fr];//для unsigned char можно использовать 64 вместо size_fr

	for (int i = 0; i < size_fr; i++)
	{
		frequency[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		frequency[arr[i]]++;
	}

	for (int i = 0, j = 0; i < size_fr; i++)
	{
		chet -= int(frequency[i]);
		if (odd && chet<N / 2 + 1)
		{
			med = unsigned char(i);
			break;
		}

		if (!odd && chet <= N / 2)
		{
			med = unsigned char(j);
			break;
		}
		if (frequency[i] != 0) j = i;
	}

	delete[] frequency;
	return med;
}

double determinant(const double mat[], int M)//метод Гаусса
{
	double det = 1.0;
	double **L = new double*[M];
	for (int i = 0; i < M; i++)
	{
		L[i] = new double[M];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			L[i][j] = mat[i*M + j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = i + 1; j < M; j++)
		{
			for (int k = i + 1; k < M; k++)
			{
				if (L[i][i] == 0.0)
				{
					for (int p = i + 1; p < M; p++) {
						if (L[p][i] != 0.0) {
							double *f = L[p];
							L[p] = L[i];
							L[i] = f;
							det *= -1.0;
							break;
						}
						else det = 0.0;
					}
				}
				if (det != 0.0) L[j][k] -= L[i][k] * L[j][i] / L[i][i];
			}
		}
		det *= L[i][i];
	}
	for (int i = 0; i < M; i++)
		delete[] L[i];
	delete[] L;
	return det;
}