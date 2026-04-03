
#include "Json.hpp"
#include <vector>

namespace Json_std
{
	std::vector<std::string> get_tokens(void)
	{

		// Fazer trim

		std::fstream file(JSON_FILE, std::fstream::in);
		std::string tmp, data;
		if (!file.is_open())
			return {};
		while (std::getline(file, tmp))
		{
			data += tmp;
		}
		if (data.empty())
		{
			file.close();
			return {};
		}
		std::vector<std::string> tokens;
		std::regex ReGex(MATCH_EXP);
		std::sregex_iterator start(data.begin(), data.end(), ReGex);
		std::sregex_iterator end;
		while (start != end)
		{
			tokens.push_back(start->str());
			start++;
		}
		file.close();
		return (tokens);
	}

	bool expect(std::vector<std::string> &tokens, std::string chars, size_t &index)
	{
		if (index < tokens.size() && !(tokens.at(index) == chars))
			return (false);
		index++;
		return (true);
	}

	int id(std::vector<std::string> &tokens, size_t &index)
	{
		if (!expect(tokens, "\"id\"", index))
			return -1;
		if (!expect(tokens, ":", index))
			return -1;
		if (index >= tokens.size())
			return -1;
		int ans = std::stoi(tokens.at(index++));
		return (ans);
	}

	void erse_start_quotes(std::string &str)
	{
		if (str.empty())
			return;
		size_t i = str.find_first_not_of("\t ");
		if (i == str.npos)
			return ;
		str.erase(0, i + 1);
		i = str.find_last_not_of("\t ");
		if (i == str.npos)
			return ;
		str.erase(i);
	}

	std::string description(std::vector<std::string> &tokens, size_t &index)
	{
		if (!expect(tokens, "\"description\"", index))
			return {};
		if (!expect(tokens, ":", index))
			return {};
		if (index >= tokens.size())
			return {};
		std::string ans = std::move(tokens.at(index++));
		erse_start_quotes(ans);
		return (ans);
	}

	std::string status(std::vector<std::string> &tokens, size_t &index)
	{
		if (!expect(tokens, "\"status\"", index))
			return {};
		if (!expect(tokens, ":", index))
			return {};
		if (index >= tokens.size())
			return {};
		std::string ans = std::move(tokens.at(index++));
		erse_start_quotes(ans);
		return (ans);
	}

	Task objects(std::vector<std::string> &tokens, size_t &index)
	{

		int my_id;
		std::string stat, descrip;
		if (!expect(tokens, "{", index))
			return {};
		my_id = id(tokens, index);
		if (my_id <= -1 || !expect(tokens, ",", index))
			return {};
		descrip = description(tokens, index);
		if (!expect(tokens, ",", index))
			return {};
		stat = status(tokens, index);
		if (!expect(tokens, "}", index))
			return {};
		Task task(descrip);
		task.update_status(stat);
		return task;
	}

	std::vector<Task> task_from_json(void)
	{
		std::vector<std::string> tokens = get_tokens();
		std::vector<Task> tmp;
		Task aux;
		if (tokens.empty())
			return {};
		size_t i = 0;
		if (!expect(tokens, "[", i))
			return {};
		aux = objects(tokens, i);
		if (aux.get_id() <= -1)
			return {};
		tmp.push_back(aux);
		if (expect(tokens, "]", i) && i >= tokens.size())
			return (tmp);
		while (true)
		{
			if (!expect(tokens, ",", i))
				break;
			aux = objects(tokens, i);
			if (aux.get_id() <= -1)
				return {};
			tmp.push_back(aux);
		}
		if (expect(tokens, "]", i) && i >= tokens.size())
			return tmp;
		return {};
	}

	void task_to_json(std::vector<Task> &tasks)
	{
		std::fstream file(JSON_FILE, std::fstream::out | std::fstream::trunc);
		if (tasks.empty()) {
			file.close();
			return ;
		}
		size_t i = 0;
		file << "[" << std::endl;
		for (; i < tasks.size(); i++)
		{
			if (i + 1 == tasks.size())
				break;
			Task &tmp = tasks[i];
			file << "\t{" << std::endl;
			file << "\t\t\"id\" : " << tmp.get_id() << ",\n";
			file << "\t\t\"description\" : " << PUT_IN_QUOTES(tmp.get_desc()) << ",\n";
			file << "\t\t\"status\" : " << PUT_IN_QUOTES(tmp.get_status()) << std::endl;
			file << "\t}," << std::endl;
		}
		Task &tmp = tasks[i];
		file << "\t{" << std::endl;
		file << "\t\t\"id\" : " << tmp.get_id() << ",\n";
		file << "\t\t\"description\" : " << PUT_IN_QUOTES(tmp.get_desc()) << ",\n";
		file << "\t\t\"status\" : " << PUT_IN_QUOTES(tmp.get_status()) << std::endl;
		file << "\t}" << "\n";
		file << "]" << std::endl;
		file.close();
	}

}
