pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'pushd exercises/sams-teach-urself-cpp/L9'
                sh 'rm -rf build'
                sh 'cd build'
                sh 'cmake ..'
                sh 'make -j`nproc`'
                sh 'cd ..'
                sh 'popd
            }
        }
    }
}


