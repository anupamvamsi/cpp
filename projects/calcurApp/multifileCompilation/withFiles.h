#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int prng();
void print_vector(std::vector<int> guesses);
std::vector<int> guesser(int random_num);
void print_high_score(int num_of_guesses);
void play_game();
int player_choice();