/*
 * string_lib.inc
 *
 * Description:
 * Some methods for string management in DXL DOORS language;
 * Include the .inc file in your .dxl in the following way:
 * #include "<path>\string_lib.inc"
 * 
 * History:
 * [26-06-2022] LMacavero
 *  - add methods and change extension in .inc
 * [18-02-2022] LMacavero
 *  - initial commit
*/

string capitalize(string str)
{
	/*
		Converts the string str to upper case
	*/
	int i = 0
	string temp = ""
	for (i = 0; i < length(str); i++){
		if (str[i] >= charOf(97) and str[i] <= charOf(122)){
			temp = temp charOf(intOf(str[i]) - 32)""
		} else {
			temp = temp str[i]""
		}
		
	}
	return temp
}

// ------------------------------------------------------------------------

string casefold(string str)
{
	/*
		Converts the string str to lower case
	*/
	int i = 0
	string temp = ""
	for (i = 0; i < length(str); i++){
		if (str[i] >= charOf(65) and str[i] <= charOf(90)){
			temp = temp charOf(intOf(str[i]) + 32)""
		} else {
			temp = temp str[i]""
		}
		
	}
	return temp
}

// ------------------------------------------------------------------------

int count(string str, char character)
{
	/*
		Returns the number of times a specified value occurs in a string
	*/
	int i = 0
	int counter = 0
	for (i = 0; i < length(str); i++){
		if (str[i] == character){
			counter++
		}
	}
	return counter
}

// ------------------------------------------------------------------------

bool endswith(string str, string ending_string)
{
	/*
		Returns true if the string str ends with the specified value ending_string
	*/
	int i = 0
	int j = length(ending_string)-1
	int counter = 0
	for (i = length(str) - 1; i >= 0; i--){
		if (j < 0){
			break
		}
		if (str[i] != ending_string[j]){
			break
		}
		j--
		counter++
	}
	return counter == length(ending_string)
}

// ------------------------------------------------------------------------

bool str_contains(string str, char c)
{
	/*
		Returns true if str contains char c
	*/
	int c_idx = 0
	Buffer buf = create()
	buf += str
	c_idx = contains(buf, c,0)
	delete(buf)
	return c_idx != -1
}

// ------------------------------------------------------------------------

bool str_contains(string str, string s)
{
	/*
		Returns true if str contains s
	*/
	int s_idx = 0
	Buffer buf = create()
	buf += str
	s_idx = contains(buf, s,0)
	delete(buf)
	return s_idx != -1
}

// ------------------------------------------------------------------------

int index(string str, string s)
{
	/*
		Finds the first occurrence of the specified string s in the string str; 
		if not found, returns -1
	*/
	int s_idx = 0
	Buffer buf = create()
	buf += str
	s_idx = contains(buf, s,0)
	delete(buf)
	return s_idx 
}

// ------------------------------------------------------------------------

int index(string str, char c)
{
	/*
		Finds the first occurrence of the specified char c in the string str; 
		if not found, returns -1
	*/
	int c_idx = 0
	Buffer buf = create()
	buf += str
	c_idx = contains(buf, c,0)
	delete(buf)
	return c_idx 
}

// ------------------------------------------------------------------------

string replace(string str, string old_s, string new_s)
{
	/*
		Replace string old_s with new_s in str
	*/
	int offset = 0
    int ln = 0
    string s_temp = ""
    string result = ""

    s_temp = str
    while(findPlainText(s_temp, old_s, offset, ln, true))
    {
        result = result  s_temp[0 : offset - 1] new_s
        s_temp = s_temp[offset + ln : ] ""
    }
    result = result s_temp

    if(result == "")
    {
        return str
    }
    else
    {
        return result
    }
}

// ------------------------------------------------------------------------

string replace(string str, string old_s, char new_c)
{
	/*
		Replace string old_s with char c in str
	*/
	int offset = 0
    int ln = 0
    string s_temp = ""
    string result = ""

    s_temp = str
    while(findPlainText(s_temp, old_s, offset, ln, true))
    {
        result = result  s_temp[0 : offset - 1] new_c""
        s_temp = s_temp[offset + ln : ] ""
    }
    result = result s_temp

    if(result == "")
    {
        return str
    }
    else
    {
        return result
    }
}

// ------------------------------------------------------------------------

string replace(string str, char old_c, char new_c)
{
	/*
		Replace all chars old_c with char c in str
	*/
	string s_temp = ""
	int i = 0
	for (i = 0; i < length(str); i++){
		if (str[i] == old_c){
			s_temp = s_temp new_c""
		} else {
			s_temp = s_temp str[i]""
		}
	}
	return s_temp
}

// ------------------------------------------------------------------------

string replace(string str, char old_c, string new_s)
{
	/*
		Replace all chars old_c with string new_s in str
	*/
	string s_temp = ""
	int i = 0
	for (i = 0; i < length(str); i++){
		if (str[i] == old_c){
			s_temp = s_temp new_s
		} else {
			s_temp = s_temp str[i]""
		}
	}
	return s_temp
}

// ------------------------------------------------------------------------

int line_counter(string str)
{
	/*
		Returns the number of lines in a string str
	*/
	Buffer buf = create()
	buf += str
	int i = 0
	int counter = 0
	int last_eol = 0

	for(i = 0;i <= length(buf); i++){
		if(buf[i] == charOf(10)){
			counter++
			last_eol = i
		}
		if(i == length(buf) and i > last_eol){
			counter++
		}
	}
	delete(buf)
	return counter
}

// ------------------------------------------------------------------------

bool startswith(string str, string starting_string)
{
	/*
		Returns true if the string str starts with the specified value starting_string
	*/
	int i = 0
	int l_ststr = length(str)
	string reduced_string = str[0:l_ststr-1]
	
	if (reduced_string == str){
		return true
	}
	return false
}

// ------------------------------------------------------------------------

string join(string str_arr[], string sep)
{
	/*
		Joins elements of an iterable with separator sep
	*/
	int len = sizeof(str_arr)
	int i = 0
	string s_temp = ""
	for (i = 0; i < len; i++){
		if (i == len - 1){ s_temp = s_temp str_arr[i]}
		else {s_temp = s_temp str_arr[i] sep}
	}	
	return s_temp
}

// ------------------------------------------------------------------------

string join(char c_arr[], string sep)
{
	/*
		Joins elements of an iterable with separator sep
	*/
	int len = sizeof(c_arr)
	int i = 0
	string s_temp = ""
	for (i = 0; i < len; i++){
		if (i == len - 1){ s_temp = s_temp c_arr[i]""}
		else {s_temp = s_temp c_arr[i]"" sep}
	}	
	return s_temp
}

