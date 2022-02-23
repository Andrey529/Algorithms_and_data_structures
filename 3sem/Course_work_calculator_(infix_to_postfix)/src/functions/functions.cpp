#ifndef COURSEWORK_FUNCTIONS_CPP
#define COURSEWORK_FUNCTIONS_CPP

#include "../../headers/functions/functions.h"

void setParanthesis(std::string *expression){
    stack<char> stackForParentHesis;
    std::string partOfString;
    int nowPos;
    std::string tempStr = *expression;

    bool flagExit = true;

    for (int i = 0; i < tempStr.size(); i++){
        if (tempStr[i] == '^'){
            nowPos = i;
            flagExit = true;
            while (flagExit) {
                if (i-1 == 0) {
                    tempStr.insert(0,"(");
                    flagExit = false;
                    break;
                }
                else{
                    i--;
                    if (tempStr[i] == ' ') continue;
                    else if( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ) {
                        while ( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ){
                            if (i-1 == 0){
                                tempStr.insert(0,"(");
                                flagExit = false;
                                break;
                            }
                            else{
                                i--;
                            }
                        }
                        tempStr.insert(i+1,"(");
                        flagExit = false;
                    }
                    else if (tempStr[i] == ')') {
                        if (i == 0){
                            tempStr.insert(0,"(");
                            flagExit = false;
                            break;
                        }
                        stackForParentHesis.push(')');
                        while (!stackForParentHesis.isEmpty()){
                            if ((i-1) == 0){
                                tempStr.insert(0,"(");
                                flagExit = false;
                                break;
                            }
                            i--;
                            if (tempStr[i] == '('){
                                stackForParentHesis.pop();
                            }
                            else if(tempStr[i] == ')'){
                                stackForParentHesis.push(')');
                            }
                        }
                        if (!flagExit) {
                            break;
                        }
                        while (true) {
                            if (i-1 == 0){
                                tempStr.insert(0,"(");
                                flagExit = false;
                                break;
                            }
                            i--;
                            if (tempStr[i] == ' ') continue;
                            else if( (tempStr[i] == '+') || (tempStr[i] == '-') || (tempStr[i] == '*') || (tempStr[i] == '/') || (tempStr[i] == '^') ){
                                i++;
                                break;
                            }
                            else if( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ) {
                                while ( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ){
                                    i--;
                                }
                                break;
                            }
                        }
                        tempStr.insert(i+1,"(");
                        flagExit = false;
                    }
                }
            }
            i = nowPos;
            while (!stackForParentHesis.isEmpty()){
                stackForParentHesis.pop();
            }
            flagExit = true;
            while (flagExit){
                if (i+1 == tempStr.size()) {
                    tempStr.push_back(')');
                    flagExit = false;
                    i = tempStr.size() - 1;
                    break;
                }
                else{
                    i++;
                    if (tempStr[i] == ' ') continue;
                    else if( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ) {
                        while ( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ){
                            if ( (tempStr[i] == '\0') || (tempStr[i+1] == '\0')){
                                tempStr.push_back(')');
                                flagExit = false;
                                break;
                            }
                            else{
                                i++;
                            }
                        }
                        if (!flagExit){
                            break;
                        }
                        tempStr.insert(i,")");
                        flagExit = false;
                    }
                    else if (tempStr[i] == '(') {
                        if (tempStr[i] == '\0'){
                            tempStr.push_back(')');
                            flagExit = false;
                            break;
                        }
                        stackForParentHesis.push('(');
                        while (!stackForParentHesis.isEmpty()){
                            if (tempStr[i+1] == '\0'){
                                tempStr.push_back(')');
                                flagExit = false;
                                break;
                            }
                            i++;
                            if (tempStr[i] == ')'){
                                stackForParentHesis.pop();
                            }
                            else if(tempStr[i] == '('){
                                stackForParentHesis.push('(');
                            }
                        }
                        if (!flagExit) {
                            break;
                        }
                        while (true) {
                            if (tempStr[i+1] == '\0'){
                                tempStr.push_back(')');
                                flagExit = false;
                                break;
                            }
                            i++;
                            if (tempStr[i] == ' ') continue;
                            else if( (tempStr[i] == '+') || (tempStr[i] == '-') || (tempStr[i] == '*') || (tempStr[i] == '/') || (tempStr[i] == '^') ){
                                while (tempStr[i] != ')'){
                                    i--;
                                }
                                break;
                            }
                            else if( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ) {
                                while ( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ){
                                    i++;
                                }
                                break;
                            }
                        }
                        if (!flagExit){
                            break;
                        }
                        tempStr.insert(i+1,")");
                        flagExit = false;
                    }
                }
            }
            i = nowPos+1;
        }
    }


    for (int i = 0; i < tempStr.size(); i++){
        if ( (tempStr[i] == '*') || (tempStr[i] == '/') ){
            nowPos = i;
            flagExit = true;
            while (flagExit) {
                if (i-1 == 0) {
                    tempStr.insert(0,"(");
                    flagExit = false;
                    break;
                }
                else{
                    i--;
                    if (tempStr[i] == ' ') continue;
                    else if( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ) {
                        while ( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ){
                            if (i-1 == 0){
                                tempStr.insert(0,"(");
                                flagExit = false;
                                break;
                            }
                            else{
                                i--;
                            }
                        }
                        tempStr.insert(i+1,"(");
                        flagExit = false;
                    }
                    else if (tempStr[i] == ')') {
                        if (i == 0){
                            tempStr.insert(0,"(");
                            flagExit = false;
                            break;
                        }
                        stackForParentHesis.push(')');
                        while (!stackForParentHesis.isEmpty()){
                            if ((i-1) == 0){
                                tempStr.insert(0,"(");
                                flagExit = false;
                                break;
                            }
                            i--;
                            if (tempStr[i] == '('){
                                stackForParentHesis.pop();
                            }
                            else if(tempStr[i] == ')'){
                                stackForParentHesis.push(')');
                            }
                        }
                        if (!flagExit) {
                            break;
                        }
                        while (true) {
                            if (i-1 == 0){
                                tempStr.insert(0,"(");
                                flagExit = false;
                                break;
                            }
                            i--;
                            if (tempStr[i] == ' ') continue;
                            else if( (tempStr[i] == '(') || (tempStr[i] == '+') || (tempStr[i] == '-') || (tempStr[i] == '*') || (tempStr[i] == '/') || (tempStr[i] == '^') ){
                                i++;
                                break;
                            }
                            else if( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ) {
                                while ( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ){
                                    i--;
                                }
                                break;
                            }
                        }
                        tempStr.insert(i+1,"(");
                        flagExit = false;
                    }
                }
            }
            i = nowPos;
            while (!stackForParentHesis.isEmpty()){
                stackForParentHesis.pop();
            }
            flagExit = true;
            while (flagExit){
                if (i+1 == tempStr.size()) {
                    tempStr.push_back(')');
                    flagExit = false;
                    i = tempStr.size() - 1;
                    break;
                }
                else{
                    i++;
                    if (tempStr[i] == ' ') continue;
                    else if( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ) {
                        while ( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ){
                            if ( (tempStr[i] == '\0') || (tempStr[i+1] == '\0')){
                                tempStr.push_back(')');
                                flagExit = false;
                                break;
                            }
                            else{
                                i++;
                            }
                        }
                        if (!flagExit){
                            break;
                        }
                        tempStr.insert(i,")");
                        flagExit = false;
                    }
                    else if (tempStr[i] == '(') {
                        if (tempStr[i] == '\0'){
                            tempStr.push_back(')');
                            flagExit = false;
                            break;
                        }
                        stackForParentHesis.push('(');
                        while (!stackForParentHesis.isEmpty()){
                            if (tempStr[i+1] == '\0'){
                                tempStr.push_back(')');
                                flagExit = false;
                                break;
                            }
                            i++;
                            if (tempStr[i] == ')'){
                                stackForParentHesis.pop();
                            }
                            else if(tempStr[i] == '('){
                                stackForParentHesis.push('(');
                            }
                        }
                        if (!flagExit) {
                            break;
                        }
                        while (true) {
                            if (tempStr[i+1] == '\0'){
                                tempStr.push_back(')');
                                flagExit = false;
                                break;
                            }
                            i++;
                            if (tempStr[i] == ' ') continue;
                            else if( (tempStr[i] == '+') || (tempStr[i] == '-') || (tempStr[i] == '*') || (tempStr[i] == '/') || (tempStr[i] == '^') ){
                                while (tempStr[i] != ')'){
                                    i--;
                                }
                                break;
                            }
                            else if( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ) {
                                while ( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ){
                                    i++;
                                }
                                break;
                            }
                        }
                        if (!flagExit){
                            break;
                        }
                        tempStr.insert(i+1,")");
                        flagExit = false;
                    }
                }
            }
            i = nowPos+1;
        }
    }


    for (int i = 0; i < tempStr.size(); i++){
        if ( (tempStr[i] == '+') || (tempStr[i] == '-') ){
            nowPos = i;
            flagExit = true;
            while (flagExit) {
                if (i-1 == 0) {
                    tempStr.insert(0,"(");
                    flagExit = false;
                    break;
                }
                else{
                    i--;
                    if (tempStr[i] == ' ') continue;
                    else if( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ) {
                        while ( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ){
                            if (i-1 == 0){
                                tempStr.insert(0,"(");
                                flagExit = false;
                                break;
                            }
                            else{
                                i--;
                            }
                        }
                        tempStr.insert(i+1,"(");
                        flagExit = false;
                    }
                    else if (tempStr[i] == ')') {
                        if (i == 0){
                            tempStr.insert(0,"(");
                            flagExit = false;
                            break;
                        }
                        stackForParentHesis.push(')');
                        while (!stackForParentHesis.isEmpty()){
                            if ((i-1) == 0){
                                tempStr.insert(0,"(");
                                flagExit = false;
                                break;
                            }
                            i--;
                            if (tempStr[i] == '('){
                                stackForParentHesis.pop();
                            }
                            else if(tempStr[i] == ')'){
                                stackForParentHesis.push(')');
                            }
                        }
                        if (!flagExit) {
                            break;
                        }
                        while (true) {
                            if (i-1 == 0){
                                tempStr.insert(0,"(");
                                flagExit = false;
                                break;
                            }
                            i--;
                            if (tempStr[i] == ' ') continue;
                            else if( (tempStr[i] == '+') || (tempStr[i] == '-') || (tempStr[i] == '*') || (tempStr[i] == '/') || (tempStr[i] == '^') ){
                                i++;
                                break;
                            }
                            else if( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ) {
                                while ( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ){
                                    i--;
                                }
                                break;
                            }
                        }
                        tempStr.insert(i+1,"(");
                        flagExit = false;
                    }
                }
            }
            i = nowPos;
            while (!stackForParentHesis.isEmpty()){
                stackForParentHesis.pop();
            }
            flagExit = true;
            while (flagExit){
                if (i+1 == tempStr.size()) {
                    tempStr.push_back(')');
                    flagExit = false;
                    i = tempStr.size() - 1;
                    break;
                }
                else{
                    i++;
                    if (tempStr[i] == ' ') continue;
                    else if( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ) {
                        while ( ((tempStr[i] >= '0') && (tempStr[i] <= '9')) || (tempStr[i] == '.') ){
                            if ( (tempStr[i] == '\0') || (tempStr[i+1] == '\0')){
                                tempStr.push_back(')');
                                flagExit = false;
                                break;
                            }
                            else{
                                i++;
                            }
                        }
                        if (!flagExit){
                            break;
                        }
                        tempStr.insert(i,")");
                        flagExit = false;
                    }
                    else if (tempStr[i] == '(') {
                        if (tempStr[i] == '\0'){
                            tempStr.push_back(')');
                            flagExit = false;
                            break;
                        }
                        stackForParentHesis.push('(');
                        while (!stackForParentHesis.isEmpty()){
                            if (tempStr[i+1] == '\0'){
                                tempStr.push_back(')');
                                flagExit = false;
                                break;
                            }
                            i++;
                            if (tempStr[i] == ')'){
                                stackForParentHesis.pop();
                            }
                            else if(tempStr[i] == '('){
                                stackForParentHesis.push('(');
                            }
                        }
                        if (!flagExit) {
                            break;
                        }
                        while (true) {
                            if (tempStr[i+1] == '\0'){
                                tempStr.push_back(')');
                                flagExit = false;
                                break;
                            }
                            i++;
                            if (tempStr[i] == ' ') continue;
                            else if( (tempStr[i] == '+') || (tempStr[i] == '-') || (tempStr[i] == '*') || (tempStr[i] == '/') || (tempStr[i] == '^') ){
                                while (tempStr[i] != ')'){
                                    i--;
                                }
                                break;
                            }
                            else if( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ) {
                                while ( (tempStr[i] >= 'a') && (tempStr[i] <= 'z') ){
                                    i++;
                                }
                                break;
                            }
                        }
                        if (!flagExit){
                            break;
                        }
                        tempStr.insert(i+1,")");
                        flagExit = false;
                    }
                }
            }
            i = nowPos+1;
        }
    }
    *expression = tempStr;
}


void inputExpression(std::string *expression){

    getline(std::cin, *expression);


    //check for not empty expression
    if (expression->empty())
        throw std::invalid_argument("String with expression is empty");



    // checks correct functions in expression
    for (std::string::iterator it = expression->begin(); it != expression->end(); it++) {
        if ( ((*it) >= 'a') && ((*it) <= 'z') ){  // cos, sin, tg, ctg, ln, log, sqrt, abs, pi, e
            if ( ((it+4) != expression->end()) &&
                ( ((*it) == 's') && ((*(it+1)) == 'q') && ((*(it+2)) == 'r') && ((*(it+3)) == 't')) ){
                it += 4;
                std::string::iterator nowPos = (it-1);
                while (true){
                    if ((*it) == ' ') {
                        if ((it+1) != expression->end()){
                            it++;
                        }
                        else{
                            throw std::invalid_argument("expression entered incorrectly:"
                                                        "expression can not end with function");
                        }
                    }
                    else if( (*it) == '(' ){
                        break;
                    }
                    else{
                        throw std::invalid_argument("expression entered incorrectly: unknown word");
                    }

                }
                while (it != nowPos)
                    it--;
            }
            else if ( ((it+3) != expression->end()) &&
                ( ( ((*it) == 'c') && ((*(it+1)) == 'o') && ((*(it+2)) == 's') )
                || ( ((*it) == 's') && ((*(it+1)) == 'i') && ((*(it+2)) == 'n') )
                || ( ((*it) == 'c') && ((*(it+1)) == 't') && ((*(it+2)) == 'g') )
                || ( ((*it) == 'l') && ((*(it+1)) == 'o') && ((*(it+2)) == 'g') )
                || ( ((*it) == 'a') && ((*(it+1)) == 'b') && ((*(it+2)) == 's') ) )   ){

                it += 3;
                std::string::iterator nowPos = (it - 1);
                while (true){
                    if ((*it) == ' ') {
                        if ((it+1) != expression->end()){
                            it++;
                        }
                        else{
                            throw std::invalid_argument("expression entered incorrectly:"
                                                        "expression can not end with function");
                        }
                    }
                    else if( (*it) == '(' )
                        break;
                    else
                        throw std::invalid_argument("expression entered incorrectly: unknown word");
                }
                while (it != nowPos)
                    it--;

            }
            else if ( ((it+2) == expression->end()) && ( ((*it) == 'p') && ((*(it+1) == 'i')) )  ) {
                break;
            }
            else if ( ((it+2) <= expression->end()) &&
                ( ((*it) == 'p') && ((*(it+1) == 'i')) )  ) {

                it += 2;
                std::string::iterator nowPos = (it - 1);
                while (true) {
                    if ((*it) == ' ') {
                        if ((it+1) != expression->end()){
                            it++;
                        }
                        else{
                            break;
                        }
                    }
                    else if (((*it) == ')') || ((*it) == '+') || ((*it) == '-')
                               || ((*it) == '*') || ((*it) == '/') || ((*it) == '^'))
                        break;
                    else
                        throw std::invalid_argument("expression entered incorrectly: unknown word");
                }
                while (it != nowPos)
                    it--;
            }
            else if ( ((it+2) != expression->end()) &&
                ( ( ((*it) == 't') && ((*(it+1) == 'g')) ) || ( ((*it) == 'l') && ((*(it+1) == 'n')) ) ) ){
                    it += 2;
                    std::string::iterator nowPos = (it - 1);
                    while (true){
                        if ((*it) == ' ') {
                            if ((it+1) != expression->end()){
                                it++;
                            }
                            else{
                                throw std::invalid_argument("expression entered incorrectly:"
                                                            "expression can not end with function");
                            }
                        }
                        else if( (*it) == '(' )
                            break;
                        else
                            throw std::invalid_argument("expression entered incorrectly: unknown word");
                    }
                    while (it != nowPos)
                        it--;
            }
            else if ((*it) == 'e'){
                if ((it+1) != expression->end()){
                    it++;
                    std::string::iterator nowPos = (it-1);
                    while (true){
                        if ((*it) == ' ') {
                            if ((it+1) != expression->end()){
                                it++;
                            }
                            else{
                                break;
                            }
                        }
                        else if ( ((*it) == ')') || ((*it) == '+') || ((*it) == '-')
                                  || ((*it) == '*') || ((*it) == '/') || ((*it) == '^'))
                            break;
                        else
                            throw std::invalid_argument("expression entered incorrectly: unknown word");
                    }
                    while (it != nowPos)
                        it--;
                }
            }
            else{
                throw std::invalid_argument("expression entered incorrectly: unknown word");
            }
        }
    }


    // checks for operands
    for (std::string::iterator it = expression->begin(); it != expression->end(); it++) {
        if (  (((*it) >= '0') && ((*it) <= '9')) || ((*it) == '.')   ) {
            std::string::iterator nowPos = it;

            if ((it+1) != expression->end()){
                it++;
                while (true) {
                    if (  (((*it) >= '0') && ((*it) <= '9')) || ((*it) == '.')   ) {
                        nowPos = it;
                        if ((it+1) != expression->end()){
                            it++;
                        }
                        else{
                            break;
                        }
                    }
                    else if ( ((*it) == '+') || ((*it) == '-') || ((*it) == '*') || ((*it) == '/') || ((*it) == '^') ) {
                        break;
                    }
                    else if ((*it) == ')') {
                        break;
                    }
                    else if ((*it) == ' ') {
                        nowPos = it;
                        if ((it+1) != expression->end()){
                            it++;
                            while (true) {
                                if ( ((*it) == '+') || ((*it) == '-') || ((*it) == '*') || ((*it) == '/') || ((*it) == '^') ) {
                                    break;
                                }
                                else if ((*it) == ')') {
                                    break;
                                }
                                else if ((*it) == ' '){
                                    nowPos = it;
                                    if ((it+1) != expression->end()) {
                                        it++;
                                    }
                                    else{
                                        break;
                                    }
                                }
                                else{
                                    throw std::invalid_argument("expression entered incorrectly: after operands can "
                                                                "stay only \")\" or operators");
                                }
                            }
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        throw std::invalid_argument("expression entered incorrectly: after operands can stay only \")\" or operators");
                    }
                }
                while (it != nowPos)
                    it--;
            }
        }
    }

    for (std::string::iterator it = expression->end(); it != expression->begin(); it--) {
        if (  (((*it) >= '0') && ((*it) <= '9')) || ((*it) == '.')   ) {
            std::string::iterator nowPos = it;

            if ((it-1) != expression->begin()){
                it--;
                while (true) {
                    if (  (((*it) >= '0') && ((*it) <= '9')) || ((*it) == '.')   ) {
                        nowPos = it;
                        if ((it-1) != expression->begin()){
                            it--;
                        }
                        else
                            break;
                    }
                    else if ( ((*it) == '+') || ((*it) == '-') || ((*it) == '*') || ((*it) == '/') || ((*it) == '^') ) {
                        break;
                    }
                    else if ((*it) == '(') {
                        break;
                    }
                    else if ((*it) == ' ') {
                        nowPos = it;
                        if ((it-1) != expression->begin()){
                            it--;
                            while (true) {
                                if ( ((*it) == '+') || ((*it) == '-') || ((*it) == '*') || ((*it) == '/') || ((*it) == '^') ) {
                                    break;
                                }
                                else if ((*it) == '(') {
                                    break;
                                }
                                else if ((*it) == ' '){
                                    if ((it-1) != expression->begin()) {
                                        it--;
                                    }
                                    else{
                                        break;
                                    }
                                }
                                else{
                                    throw std::invalid_argument("expression entered incorrectly: before operands can "
                                                                "stay only \"(\" or operators");
                                }
                            }
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        throw std::invalid_argument("expression entered incorrectly: before operands can stay only \"(\" or operators");
                    }
                }
                while (it != nowPos)
                    it++;
            }
        }
    }



    // checks for operators
    for (std::string::iterator it = expression->begin(); it != expression->end(); it++) {
        if ( ((*it) == '+') || ((*it) == '-') || ((*it) == '*') || ((*it) == '/') || ((*it) == '^') ) {
            std::string::iterator nowPos = it;

            if ((it+1) != expression->end()){
                it++;
                while (true) {
                    if ((*it) == ' '){
                        if ((it+1) != expression->end()){
                            nowPos = it;
                            it++;
                        }
                        else{
                            throw std::invalid_argument("expression entered incorrectly: expression can not end with operator");
                        }
                    }
                    else if(((*it) >= '0') && ((*it) <= '9')) {
                        break;
                    }
                    else if((*it) == '('){
                        break;
                    }
                    else if(((*it) >= 'a') && ((*it) <= 'z')){
                        break;
                    }
                    else {
                        throw std::invalid_argument("expression entered incorrectly: after operators can stay only "
                                                    "digits or \"(\" or functions");
                    }
                }
                while (it != nowPos){
                    it--;
                }
            }
            else {
                throw std::invalid_argument("expression entered incorrectly: expression can not end with operator");
            }
        }
    }

    for (std::string::iterator it = expression->end(); it != expression->begin(); it--) {
        if ( ((*it) == '+') || ((*it) == '-') || ((*it) == '*') || ((*it) == '/') || ((*it) == '^') ) {
            std::string::iterator nowPos = it;

            if ((it-1) != expression->begin()) {
                it--;
                while (true) {
                    if ((*it) == ' '){
                        //////////////////////////////////////////////
                        if ((it-1) >= expression->begin()){
                            /////////////////////////////////////////////
                            nowPos = it;
                            it--;
                        }
                        else{
                            throw std::invalid_argument("expression entered incorrectly: expression can not begin with operator");
                        }
                    }
                    else if(((*it) >= '0') && ((*it) <= '9')) {
                        break;
                    }
                    else if (((*it) == 'e') || (((*it) == 'i') && ((*(it-1) == 'p'))) ){
                        break;
                    }
                    else if((*it) == ')'){
                        break;
                    }
                    else {
                        throw std::invalid_argument("expression entered incorrectly: before operators can stay only digits or \")\"");
                    }
                }
                while (it != nowPos){
                    it++;
                }
            }
            else {
                throw std::invalid_argument("expression entered incorrectly: expression can not begin with operator");
            }
        }
    }

    // checks for dot
    for (std::string::iterator it = expression->begin(); it != expression->end(); it++){
        if ((*it) == '.') {
            if ((it+1) != expression->end()){
                it++;
                while (true){
                    if (((*it) >= '0') && ((*it) <= '9')){
                        break;
                    }
                    else{
                        throw std::invalid_argument("expression entered incorrectly: after \".\" can stay only digits");
                    }
                }
            }
            else {
                throw std::invalid_argument("expression entered incorrectly: expression can not end with \".\"");
            }
        }
    }

    for (std::string::iterator it = expression->end(); it != expression->begin(); it--) {
        if ((*it) == '.') {
            if ((it-1) != expression->begin()) {
                it--;
                while (true) {
                    if (((*it) >= '0') && ((*it) <= '9')){
                        break;
                    }
                    else{
                        throw std::invalid_argument("expression entered incorrectly: before \".\" can stay only digits");
                    }
                }
            }
            else {
                throw std::invalid_argument("expression entered incorrectly: expression can not begin with \".\"");
            }
        }
    }

    // checks for (
    for (std::string::iterator it = expression->begin(); it != expression->end(); it++){
        if ((*it) == '(') {
            std::string::iterator nowPos = it;

            if ((it+1) != expression->end()){
                it++;
                while (true){
                    if ((*it) == ' ') {
                        if ((it+1) != expression->end()){
                            nowPos = it;
                            it++;
                        }
                        else {
                            throw std::invalid_argument("expression entered incorrectly: expression can not end with \"(\"");
                        }
                    }
                    else if (((*it) >= '0') && ((*it) <= '9')){
                        break;
                    }
                    else if ((*it) == '('){
                        break;
                    }
                    else if(((*it) >= 'a') && ((*it) <= 'z')) {
                        break;
                    }
                    else{
                        throw std::invalid_argument("expression entered incorrectly: after \"(\" can stay only \"(\""
                                                    " or digits or functions");
                    }
                }
                while (it != nowPos){
                    it--;
                }
            }
            else {
                throw std::invalid_argument("expression entered incorrectly: expression can not end with \"(\"");
            }
        }
    }


    for (std::string::iterator it = expression->end(); it != expression->begin(); it--) {
        if ((*it) == '(') {
            std::string::iterator nowPos = it;

            if ((it-1) != expression->begin()) {
                it--;
                while (true) {
                    if ((*it) == ' ') {
                        if ((it-1) != expression->begin()){
                            nowPos = it;
                            it--;
                        }
                        else{
                            break;
                        }
                    }
                    else if (((*it) >= 'a') && ((*it) <= 'z')) {
                        break;
                    }
                    else if((*it) == '('){
                        break;
                    }
                    else if ( ((*it) == '+') || ((*it) == '-') || ((*it) == '*') || ((*it) == '/') || ((*it) == '^') ){
                        break;
                    }
                    else
                        throw std::invalid_argument("expression entered incorrectly: before \"(\" can stay only "
                                                    "\"(\" or functions or operators");
                }
                while (it != nowPos){
                    it++;
                }
            }
        }
    }


    // checks for )
    for (std::string::iterator it = expression->begin(); it != expression->end(); it++) {
        if ((*it) == ')') {
            std::string::iterator nowPos = it;

            if ((it+1) != expression->end()){
                it++;
                while (true){
                    if ((*it) == ' ') {
                        if ((it+1) != expression->end()){
                            nowPos = it;
                            it++;
                        }
                        else {
                            break;
                        }
                    }
                    else if ((*it) == ')'){
                        break;
                    }
                    else if ( ((*it) == '+') || ((*it) == '-') || ((*it) == '*') || ((*it) == '/') || ((*it) == '^') ){
                        break;
                    }
                    else{
                        throw std::invalid_argument("expression entered incorrectly: after \")\" can stay only \")\" or operators");
                    }
                }
                while (it != nowPos){
                    it--;
                }
            }
        }
    }

    for (std::string::iterator it = expression->end(); it != expression->begin(); it--) {
        if ((*it) == ')') {
            std::string::iterator nowPos = it;

            if ((it-1) != expression->begin()) {
                it--;
                while (true) {
                    if ((*it) == ' ') {
                        if ((it-1) != expression->begin()){
                            nowPos = it;
                            it--;
                        }
                        else{
                            throw std::invalid_argument("expression entered incorrectly: expression can not begin with \")\"");
                        }
                    }
                    else if ((*it) == ')') {
                        break;
                    }
                    else if (((*it) >= '0') && ((*it) <= '9')) {
                        break;
                    }
                    else
                        throw std::invalid_argument("expression entered incorrectly: before \")\" can stay only \")\" or digits");
                }
                while (it != nowPos){
                    it++;
                }
            }
            else {
                throw std::invalid_argument("expression entered incorrectly: expression can not begin with \")\"");
            }
        }
    }

    // check for paranthesis balance
    stack<char> stackBalanceParanthesis;
    for (std::string::iterator it = expression->begin(); it != expression->end(); it++) {
        if ((*it) == '(') {
            stackBalanceParanthesis.push('(');
        }
        else if((*it) == ')'){
            stackBalanceParanthesis.pop();
        }
    }

    if (!stackBalanceParanthesis.isEmpty())
        throw std::invalid_argument("Count of left paranthesis not equal count of right parenthesis");

}

void convertInfixToPostfix(std::string *expression) {
    stack<std::string> stackForOperators;
    stack<bool> stackForRightParenthesis;
    std::string functions, result;
    containerType nowTypeOfContainer;

    for (std::string::iterator it = expression->begin(); it != expression->end(); it++) {
        if ((*it) == '(') {
            if (nowTypeOfContainer == containerType::FUNCTION)    stackForRightParenthesis.push(true);
            else    stackForRightParenthesis.push(false);

            nowTypeOfContainer = containerType::LEFTPARENTHESIS;
            stackForOperators.push("("); // положить в стэк
        }
        else if ((*it) == ')') {
            if (nowTypeOfContainer != containerType::RIGHTPARENTHESIS) {
                result.push_back(' ');
            }

            while (stackForOperators.getFront()->getData() != "(") {
                result += stackForOperators.getFront()->getData();
                result.push_back(' ');
                stackForOperators.pop();
            }
            if (stackForOperators.getFront()->getData() == "("){
                stackForOperators.pop();
            }

            if (stackForRightParenthesis.getFront()->getData()) { // stackForRightParenthesis.getFront()->getData() == true
                result += functions;
                result.push_back(' ');
                functions.clear();
            }
            stackForRightParenthesis.pop();

            nowTypeOfContainer = containerType::RIGHTPARENTHESIS;
        }
        else if( (((*it) >= '0') && ((*it) <= '9')) || ((*it) == '.') ) {
            // добавить в конец выходного списка
            nowTypeOfContainer = containerType::OPERAND;
            result.push_back(*it);
        }
        else if ( ((*it) >= 'a') && ((*it) <= 'z') ) {
            if ( (*it) == 'e' ) {
                result += "e";
                nowTypeOfContainer = containerType::OPERAND;
                continue;
            }
            functions += *it;
            if (functions == "pi") {
                result += "pi";
                functions.clear();
                nowTypeOfContainer = containerType::OPERAND;
                continue;
            }
            nowTypeOfContainer = containerType::FUNCTION;
        }
        else if ( ((*it) == '^') || ((*it) == '*') || ((*it) == '/') || ((*it) == '+') || ((*it) == '-') ) {

            if ( (nowTypeOfContainer == containerType::OPERAND) || (nowTypeOfContainer == containerType::FUNCTION) ) {
                result.push_back(' ');
            }
            if (nowTypeOfContainer == containerType::OPERATOR) { // unary minus
                result.push_back('-');
                nowTypeOfContainer = containerType::OPERAND;
                continue;
            }

            nowTypeOfContainer = containerType::OPERATOR;

            if (!stackForOperators.isEmpty()) {
                if ( ((*it) == '^') && (stackForOperators.getFront()->getData() == "^") ) {
                    result += stackForOperators.getFront()->getData();
                    result.push_back(' ');
                    stackForOperators.pop();
                }
                else if( (((*it) == '*') || ((*it) == '/')) && ( (stackForOperators.getFront()->getData() == "*")
                    || (stackForOperators.getFront()->getData() == "/") || (stackForOperators.getFront()->getData() == "^")) ) {
                    result += stackForOperators.getFront()->getData();
                    result.push_back(' ');
                    stackForOperators.pop();
                }
                else if ( (((*it) == '+') || ((*it) == '-')) && (stackForOperators.getFront()->getData() != "(") ) {
                    result += stackForOperators.getFront()->getData();
                    result.push_back(' ');
                    stackForOperators.pop();
                }
            }
            std::string currentSymbol( 1, *it );
            stackForOperators.push(currentSymbol);
        }
    }

    while ( !stackForOperators.isEmpty() ) {
        if (stackForOperators.getFront()->getData() != "(") {
            result += stackForOperators.getFront()->getData();
            result.push_back(' ');
        }
        stackForOperators.pop();
    }

    *expression = result;
}

double calculationPostfix(std::string *expression) {

    stack<double> stackForCalculation;
    std::string tempStr;
    double currentOperand;
    double operand1, operand2;
    for (std::string::iterator it = expression->begin(); it != expression->end(); it++) {
        if ((*it) != ' ') {
            tempStr.push_back(*it);
        }
        else {
            if (tempStr.size() == 1) {
                if (tempStr[0] == 'e'){
                    currentOperand = M_E;
                    stackForCalculation.push(currentOperand);
                    tempStr.clear();
                }
                else if ( (tempStr[0] >= 48 ) && (tempStr[0] <= 57) ) { // operands: (0,1,2,...9)
                    currentOperand = std::stod(tempStr);
                    stackForCalculation.push(currentOperand);
                    tempStr.clear();
                }
                else {  // operators: +, -, *, /, ^
                    operand2 = stackForCalculation.getFront()->getData();
                    stackForCalculation.pop();
                    operand1 = stackForCalculation.getFront()->getData();
                    stackForCalculation.pop();
                    switch (tempStr[0]) {
                        case '+':
                            operand1 = operand1 + operand2;
                            break;
                        case '-':
                            operand1 = operand1 - operand2;
                            break;
                        case '*':
                            operand1 = operand1 * operand2;
                            break;
                        case '/':
                            if (operand2 == 0) {
                                throw std::invalid_argument("impossible to do division");
                            }
                            operand1 = operand1 / operand2;
                            break;
                        case '^':
                            operand1 = pow(operand1, operand2);
                            break;
                    }
                    stackForCalculation.push(operand1);
                    tempStr.clear();
                }
            }
            else { // tempStr.size() != 1

                if ( (tempStr[1] >= 48) && (tempStr[1] <= 57) || (tempStr[1] == '.')) {  // operands with 2+ symbols (123, 329, 9923785, ...)
                    currentOperand = std::stod(tempStr);
                    stackForCalculation.push(currentOperand);
                    tempStr.clear();
                }
                else if ( (tempStr.size() == 2) && (tempStr[0] == 'p') && (tempStr[1] == 'i')) {
                    currentOperand = M_PI;
                    stackForCalculation.push(currentOperand);
                    tempStr.clear();
                }
                else { // functions: cos, sin, tg, ctg, ln, log, sqrt, abs

                    operand1 = stackForCalculation.getFront()->getData();
                    stackForCalculation.pop();

                    if (tempStr.size() == 2) { // tg, ln, pi
                        switch (tempStr[0]) {
                            case 't': // tg
                                if ((int)round(operand1) % 180 == 0){
                                    if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                        operand1 = 0;
                                        break;
                                    }
                                }
                                else if ( ((int)round(operand1) % 90 == 0) && ((int)round(operand1) % 180 != 0) ){
                                    if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                        throw std::invalid_argument("impossible to count tg()");
                                    }
                                }
                                operand1 = tan(operand1*M_PI/180);
                                break;
                            case 'l': // ln
                                if (operand1 <= 0){
                                    throw std::invalid_argument("impossible to count ln()");
                                }
                                operand1 = log(operand1);
                                break;
                        }
                    }
                    else if(tempStr.size() == 3) { // cos, sin, ctg, log, abs
                        switch (tempStr[0]) {
                            case 's':  // sin
                                if ((int)round(operand1) % 180 == 0){
                                    if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                        operand1 = 0;
                                        break;
                                    }
                                }
                                operand1 = sin(operand1*M_PI/180);
                                break;
                            case 'l':  // log
                                if (operand1 <= 0){
                                    throw std::invalid_argument("impossible to count lg()");
                                }
                                operand1 = log10(operand1);
                                break;
                            case 'a': // abs
                                operand1 = fabs(operand1);
                                break;
                            case 'c':
                                switch (tempStr[1]) {
                                    case 'o':  // cos
                                        if ( ((int)round(operand1) % 90 == 0) && ((int)round(operand1) % 180 != 0) ){
                                            if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                                operand1 = 0;
                                                break;
                                            }
                                        }
                                        operand1 = cos(operand1*M_PI/180);
                                        break;
                                    case 't':  // ctg
                                        if ( ((int)round(operand1) % 90 == 0) && ((int)round(operand1) % 180 != 0) ){
                                            if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                                operand1 = 0;
                                                break;
                                            }
                                        }
                                        else if ((int)round(operand1) % 180 == 0) {
                                            if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                                throw std::invalid_argument("impossible to count ctg()");
                                            }
                                        }
                                        operand1 = 1 / tan(operand1*M_PI/180);
                                        break;
                                }
                                break;
                        }
                    }
                    else { // sqrt
                        if (operand1 < 0){
                            throw std::invalid_argument("impossible to count sqrt()");
                        }
                        operand1 = sqrt(operand1);
                    }
                    stackForCalculation.push(operand1);
                    tempStr.clear();
                }
            }
        }
    }
    double result = stackForCalculation.getFront()->getData();
    stackForCalculation.pop();
    return result;
}

bool approximatelyEqual(double a, double b, double epsilon){
    return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

#endif //COURSEWORK_FUNCTIONS_CPP