
	/// Функция вычисления ссумарного обьема v1- обьем первой, v2 - обьем второй
	float all_v(float v1, float v2)
	{
    	return v1 + v2;  
	}

	/// Функция вычисления температуры смеси v1, t1- обьем, температура первой, v2, t2 - обьем, температура второй
	float all_temp(float v1, float v2, float t1, float t2)
	{
    	return ((v1 * t1 + v2 * t2) / (v1 + v2));  //вычисление обьема
	}
