bool BogValidator::readDict()
{
	string s;
	int i = 0;

	while (cin >> s){
		if (s == "."){
			break;
		}

		while (s.length() > 0){
			s[i] = toupper(s[i]);
			i++;
		}

		dict.insert(s);
	}

	return true;
}
