//------------------------------------------------------------------------------
//
// File Name:	Stream.c
// Author(s):	Xander Boosinger (xander.boosinger)
// Project:		Project 6
// Course:		CS230S25
//
// Copyright © 2025 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "Stream.h"
#include "Trace.h"

#include <stdlib.h>
#include <string.h>

#define ERROR_MSG_BUFFER 256

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Open a file for reading.
// (NOTE: Use fopen_s() with the "rt" option.)
// (NOTE: You must generate the following trace message if the file was not opened successfully:
//	  TraceMessage("Error: StreamOpen could not open file %s; %s", filePath, errorMsg);
//	  Where errorMsg is a char array containing the error message obtained using strerror_s().)
// Params:
//	 filePath = The file to be opened for reading.
// Returns:
//	 0 if filePath is 0 or the file could not be opened.
//	 Pointer to a FILE object if the file was opened successfully.
Stream StreamOpen(const char* filePath)
{
	char errorMsg[ERROR_MSG_BUFFER];

	if (filePath)
	{
		Stream tempstream = 0;
		strerror_s(errorMsg, sizeof(char) * ERROR_MSG_BUFFER, fopen_s(&tempstream, filePath, "rt"));

		if (tempstream)
		{
			return tempstream;
		}
	}
	
	TraceMessage("Error: StreamOpen could not open file %s; %s", filePath, errorMsg);
	return 0;
}

/**/
// Read a single integer from a stream.
// (NOTE: Verify that the stream is valid first.)
// (NOTE: Use fscanf_s() to scan the input stream for an integer.)
// Params:
//	 stream = The file stream from which to read.
// Returns:
//	 0 if the stream was not opened succesfully;
//	 otherwise, an integer value read from the file.
int StreamReadInt(Stream stream)
{
	if (stream)
	{
		int scan = 0;
		char currentcharacter = 0;
		int integer = 0;
		for (scan = fscanf_s(stream, "%c", &currentcharacter, (unsigned int)sizeof(char)); scan != EOF && !(currentcharacter >= '0' && currentcharacter <= '9'); scan = fscanf_s(stream, "%c", &currentcharacter, (unsigned int)sizeof(char)))
		{
			if (currentcharacter == '-')
			{
				fscanf_s(stream, "%c", &currentcharacter, (unsigned int)sizeof(char));
				if (currentcharacter >= '0' && currentcharacter <= '9')
				{
					fseek(stream, -1, SEEK_CUR);
					break;
				}
			}
		}
		fseek(stream, -1, SEEK_CUR);
		fscanf_s(stream, "%d", &integer);
		return integer;
	}

	TraceMessage("XXX\nError: Attempted to open invalid stream!\nXXX");
	return 0;
}
/**//**/
// Read a single float from a stream.
// (NOTE: Verify that the stream is valid first.)
// (NOTE: Use fscanf_s() to scan the input stream for a float.)
// Params:
//	 stream = The file stream from which to read.
// Returns:
//	 If the stream was opened succesfully,
//	   then return a float value read from the file,
//	   else return 0.
float StreamReadFloat(Stream stream)
{
	if (stream)
	{
		int scan = 0;
		char currentcharacter = 0;
		float floatingpoint = 0;
		for (scan = fscanf_s(stream, "%c", &currentcharacter, (unsigned int)sizeof(char)); scan != EOF && !(currentcharacter >= '0' && currentcharacter <= '9'); scan = fscanf_s(stream, "%c", &currentcharacter, (unsigned int)sizeof(char)))
		{
			if (currentcharacter == '-' || currentcharacter == '.')
			{
				fscanf_s(stream, "%c", &currentcharacter, (unsigned int)sizeof(char));
				if (currentcharacter >= '0' && currentcharacter <= '9')
				{
					fseek(stream, -1, SEEK_CUR);
					break;
				}
			}
		}
		fseek(stream, -1, SEEK_CUR);
		fscanf_s(stream, "%f", &floatingpoint);
		return floatingpoint;
	}

	TraceMessage("XXX\nError: Attempted to open invalid stream!\nXXX");
	return 0;
}

// Read a token (a single word) from a file.
// Suggested steps:
//	 - Set the first value in tokenBuffer to 0
//	 - If the stream was opened successfully,
//	   - Read a std::string ("%s") into tokenBuffer using fscanf_s()
//	 - Return tokenBuffer
// Params:
//	 stream = The file stream from which to read.
// Returns:
//	 Pointer to tokenBuffer
const char* StreamReadToken(Stream stream)
{
	if (!stream)
	{
		TraceMessage("XXX\nError: Attempted to open invalid stream!\nXXX");
		return 0;
	}
	
	static char tokenBuffer[1024];
	tokenBuffer[0] = 0;

	char currentcharacter = 0;

	for (int scan = fscanf_s(stream, "%c", &currentcharacter, (unsigned int)sizeof(currentcharacter)); scan != EOF; scan = fscanf_s(stream, "%c", &currentcharacter, (unsigned int)sizeof(currentcharacter)))//while scan != EOF, copy file to std::string
	{
		if (currentcharacter != ' ' && currentcharacter != '\n'/*currentcharacter == '['*/)
		{
			fseek(stream, -1, SEEK_CUR);
			
			break;
		}
	}

	fscanf_s(stream, "%s", &tokenBuffer, (unsigned int)_countof(tokenBuffer));

	//fseek(stream, -1, SEEK_CUR);

	return tokenBuffer;
}

/**//**/
// Close an opened stream.
// (NOTE: Do not attempt to close the stream if the pointer is null.)
// (PRO TIP: Avoid dangling pointers by setting the FILE pointer to 0.)
// Params:
//	 stream = The file stream to be closed.
void StreamClose(Stream* stream)
{
	if (stream && *stream)
	{
		fclose(*stream);
	}
	
	stream = 0;
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------*/

