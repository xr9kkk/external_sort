#include "Sequence.h"

void Sequence::read_next()
{
	eof = file.eof();
	if (!eof)
		file >> elem;
}

void Sequence::star_read(std::string filename)
{
	file.open(filename, std::ios::in);
	read_next();
	eor = eof;
}

void Sequence::star_write(std::string filename)
{
	file.open(filename, std::ios::out);
}

void Sequence::close()
{
	file.close();
}

void Sequence::copy(Sequence& x)
{
	elem.value = x.elem.value;
	file << elem;
	x.read_next();
	x.eor = x.eof || x.elem.value < elem.value;
}

void Sequence::copy_run(Sequence& x)
{
	do
	{
		copy(x);
	} while (!x.eor);
}
