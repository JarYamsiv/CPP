// basic file operations
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include "huffman.h"

#include <bitset>

using namespace std;



int write_to_file(const char* filename,int amt)
{
	srand(time(0));
	if(amt<=0)
	{
		return -1;
	}
	ofstream myfile;
	myfile.open (filename,ios::binary|ios::out|ios::trunc);
	
	for(int i=0; i<amt; i++)
	{
		char rand_num = rand()%256;
		myfile.write((char*)&rand_num,sizeof(rand_num));
	}

	myfile.close();

	return 0;
}

int simple_read(const char* filename)
{
	ifstream myfile;
	myfile.open (filename,ios::binary|ios::in);


	unsigned char c;
    while(myfile>>c)
    {
    	int x = (int)c;
    	printf("%d\n",x );
    }

}

void write_tree(Node *root,ofstream *file)
{
	if(!root)
	{
		(*file)<<999<<" ";
	}
	else
	{
		(*file)<<(int)(root->ch)<<" ";
		write_tree(root->left,file);
		write_tree(root->right,file);
	}
}

int compress(const char* filename,int n=1)
{

	//reading and counting
	ifstream myfile;
	myfile.open (filename,ios::binary|ios::in);

	streampos fsize = myfile.tellg();
    myfile.seekg( 0, ios::end );
    fsize = myfile.tellg() - fsize;
    myfile.seekg(0,ios::beg);

    // printf("filesize %d bytes\n",(int)fsize );
    //cout<<"reading as bytes:"<<endl;

    int min_freq,max_freq;
    min_freq = 255;
    max_freq = 0;

    long long unsigned int count_array[256];
    double probability[256];
    memset(count_array,0,sizeof(count_array));
    char c;

    int file_size = (int)fsize;
    unordered_map<unsigned char,long long int> freq;
    while(1)
    {
    	if(myfile.eof())break;
    	myfile.read(&c,1);
    	int x = (int)c;

    	count_array[x]++;
    	freq[c]++;
    	// printf("%d ",x);

    	
    }

    myfile.close();
    myfile.open (filename,ios::binary|ios::in);

    int* f = (int*)malloc(sizeof(int)*pow(256,n));
    memset(f,0,sizeof(f));
    char next[n];
    
    while(1)
    {
    	if(myfile.eof())break;
    	myfile.read(&c,1);
    	int x = (int)c;

    	// count_array[x]++;
    	// printf("%d ",x);

    	
    }



    double entropy = 0.0;
    double p;

    for(int i=0; i<256; i++)
    {
    	p = (double)count_array[i]/(int)fsize;
    	probability[i] = p;

    	if(p!=0)entropy -= p*log2(p);


    	
    	//if(count_array[i]!=0)printf("count (%3d) = %lld ; prob = %f information = %f\n", i, count_array[i],p,-log2(p));
    }

    printf("entropy : %f  \n",entropy );

    


	// Create a priority queue to store live nodes of
	// Huffman tree;
	priority_queue<Node*, vector<Node*>, comp> pq;

	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	unordered_map<unsigned char, string> huffmanCode;
	unordered_map<string , unsigned char> reverse_map;
	encode(root, "", huffmanCode);

	// cout << "Huffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		reverse_map[pair.second] = pair.first;

		// printf("%3d : %s\n",pair.first,pair.second.c_str() );

		if((int)pair.second.size()<min_freq) {min_freq = (int)pair.second.size();}

    	if((int)pair.second.size()>max_freq) {max_freq = (int)pair.second.size();}
	}

	// printf("min_freq: %d , max_freq : %d \n",min_freq,max_freq );


	//meta-data
	ofstream writefile,metafile;
	writefile.open("compressed/test.m",ios::binary|ios::out|ios::trunc);
	metafile.open("compressed/test.meta",ios::binary|ios::out|ios::trunc);

	metafile<<min_freq<<" "<<max_freq<<endl;
	write_tree(root,&metafile);

	myfile.close();
	//encoding
	// printf("encoding..\n");
	myfile.open (filename,ios::binary|ios::in);

	unsigned char wb=0; //write byte
	int wbc=0;;// counter goes upto 8
	string wbs;

	queue <unsigned char> wq;
	while(1)
    {	
    	if(myfile.eof())break;
    	myfile.read(&c,1);
    	wbs = huffmanCode[c];
    	// printf("%s",wbs.c_str() );
    	for(int i=0; i<wbs.size(); i++)
    	{
    		wq.push(wbs[i]);

    	}

    	if(wq.size()>8)
    	{
    		wb=0;
    		for(int i=0; i<8; i++)
    		{
    			wb = (wb<<1);
    			wb = wb | (wq.front()-'0');
    			wq.pop();
    		}
    		// std::cout<<"|" << std::bitset<8>(wb)<<"|";
    		writefile.write((char*)&wb,sizeof(wb));
    	}
    	

    }
    int padding  = (wq.size()%8) - 1;
    while(wq.size()<8)
    {
    	wq.push('0');
    }
    wb=0;
	for(int i=0; i<8; i++)
	{
		wb = (wb<<1);
		wb = wb | (wq.front()-'0');
		wq.pop();
	}
	// std::cout<<"|" << std::bitset<8>(wb)<<"|";
	writefile.write((char*)&wb,sizeof(wb));

	myfile.close();
	writefile.close();
	metafile.close();
	// printf("padding upto %d while counting from 0\n",padding);

	//decoding

	fstream readfile;
	readfile.open("compressed/test.m",ios::binary|ios::in);

	readfile.seekg(0,ios::end);
	int length = readfile.tellg();
	readfile.seekg(0,ios::beg);

	writefile.open("decompressed/test.txt",ios::binary|ios::out|ios::trunc);

	unsigned char rb;

	string code="";
	char read_bit;

	unsigned char decoded_byte;
	for(int i=0; i<length-1; i++){
		//printf("read%c\n",rb );
		readfile.read(&c,sizeof(c));
		rb = (unsigned char)c;
		for(int i=0; i<8; i++)
		{
			read_bit = rb/128;
			rb = rb<<1;
			code += read_bit+'0';
			//printf("code : %s\n",code.c_str() );
			if(reverse_map.find(code)!=reverse_map.end())
			{
				// printf("found %c\n",decoded_byte);
				decoded_byte = reverse_map[code];
				//writefile<<decoded_byte;
				writefile.write((char*)&decoded_byte,sizeof(decoded_byte));
				code="";
			}
		}

	}
	readfile.read(&c,sizeof(c));
	rb = (unsigned char)c;
	code = "";
	for (int i = 0; i < padding; ++i)
	{
		read_bit = rb/128;
			rb = rb<<1;
			code += read_bit+'0';
			//printf("code : %s\n",code.c_str() );
			if(reverse_map.find(code)!=reverse_map.end())
			{
				// printf("found %c\n",decoded_byte);
				decoded_byte = reverse_map[code];
				//writefile<<decoded_byte;
				writefile.write((char*)&decoded_byte,sizeof(decoded_byte));
				code="";
			}
	}

	readfile.close();
	return 0;
}

int decompress(const char* filename)
{

}


int main (int argc,char* argv[]) {

	if(argc<2){
		cout<<"error"<<endl;
		exit(-1);
	}

	if(strcmp(argv[1],"write")==0){
		if(argc<3){
			cout<<"invalid input"<<endl;
			exit(-1);
		}
		else{
			if(argc>3){
				if(write_to_file(argv[3],atoi(argv[2]) )!=0){
					cout<<"error";
				}
			}
			else{ 
				if(write_to_file("example.bin",atoi(argv[2]) )!=0){
					cout<<"error";
				}  
			}
		}
	}
	else if( strcmp(argv[1],"read" ) ==0 ){


		if(argc==2)compress("example.bin");
		else if(argc==3)compress(argv[2]);

	}
	else if(strcmp(argv[1],"sread")==0){
		if(argc==2)simple_read("example.bin");
		else if(argc==3)simple_read(argv[2]);
	}
	else if(strcmp(argv[1], "n") == 0){
		compress(argv[2],atoi(argv[3]));
	}
	else
	{
		cout<<"invalid command"<<endl;
		exit(-1);
	}

	
	
	
	return 0;
}

