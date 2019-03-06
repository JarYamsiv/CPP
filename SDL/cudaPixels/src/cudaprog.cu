__global__ void setpix(int **pix,int *t)
{
	pix[0][0] = t[0];
}

class CUDA
{
public:
	CUDA(int _width,int _height)
	{
		width = _width;
		height = _height;
		pixels = new int[width*height];
		int size = width*height*sizeof(int);
		cudaMalloc((void**)&pixels,size);
	}
	~CUDA()
	{
		cudaFree(pixels);
		delete [] pixels;
	}
private:
	int width,height;
	int *pixels;
};