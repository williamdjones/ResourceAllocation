
#include "RA_DISC.H"
#include <fstream>
#include <iterator>


int main()
{


	std::vector<float> time_table;
	std::vector<double> p1_vals;
	std::vector<double> p2_vals;
	std::vector<double> p1_shareSize;
	std::vector<double> p2_shareSize;
	std::vector<int> rSizes;

	//std::cout<<"Number of Trials: ";
	int trial_num = 4;
	//std::cin>>trial_num;


	double alpha = 0.5;

	int resource_size = 10;

	Agent* a = new Agent;
	Agent* b = new Agent;
	Agent* c = new Agent;
	Agent* d = new Agent;
	//Agent* e = new Agent;
	//Agent* f = new Agent;

	a->generateValueDist(resource_size);
	b->generateValueDist(resource_size);
	c->generateValueDist(resource_size);
	d->generateValueDist(resource_size);
	//e->generateValueDist(resource_size);
	//f->generateValueDist(resource_size);

	std::vector<Agent*> players;
	players.push_back(a);
	players.push_back(b);
	players.push_back(c);
	players.push_back(d);
	//players.push_back(e);
	//players.push_back(f);

	Protocol p;


	p.cut_and_choose(a,b,0.5);



	//p.last_diminisher(players);


	for(int i = 0 ; i < trial_num; i ++)
	{

		resource_size = pow(2,i);

		Agent* a = new Agent;
		a->generateValueDist(resource_size);

		Agent* b = new Agent;
		b->generateValueDist(resource_size);

		Protocol p;

		clock_t t;

		t= clock();

		p.cut_and_choose(a,b,alpha);

		t = (clock() - t);

		time_table.push_back((float)t/CLOCKS_PER_SEC);
		p1_vals.push_back(a->get_shareValue());
		p2_vals.push_back(b->get_shareValue());
		p1_shareSize.push_back(a->get_shareSize()/(double(resource_size)));
		p2_shareSize.push_back(b->get_shareSize()/(double(resource_size)));
		rSizes.push_back(resource_size);
	}

	std::ofstream output_file("output.txt");

	std::copy(time_table.begin(), time_table.end(), std::ostream_iterator<float>(output_file, ","));
	output_file << std::endl;
	std::copy(p1_vals.begin(), p1_vals.end(), std::ostream_iterator<double>(output_file, ","));
	output_file << std::endl;
	std::copy(p1_shareSize.begin(), p1_shareSize.end(), std::ostream_iterator<double>(output_file, ","));
	output_file << std::endl;
	std::copy(p2_vals.begin(), p2_vals.end(), std::ostream_iterator<double>(output_file, ","));
	output_file << std::endl;
	std::copy(p2_shareSize.begin(), p2_shareSize.end(), std::ostream_iterator<double>(output_file, ","));
	output_file << std::endl;
	std::copy(rSizes.begin(), rSizes.end(), std::ostream_iterator<int>(output_file, ","));
	output_file <<std::endl;




	return 0;

};
