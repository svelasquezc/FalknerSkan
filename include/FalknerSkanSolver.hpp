#ifndef FALKNER_SKAN_SOLVER
#define FALKNER_SKAN_SOLVER

#include <vector>
#include <Eigen/Sparse>


class FalknerSkanSolver {
    private:

    /*
    Aliases from Eigen types
    */
    using SparseMatrix = Eigen::SparseMatrix<double>;
    using Triplet = Eigen::Triplet<double>;
    using Vector = Eigen::VectorXd;
    using Solver =  Eigen::BiCGSTAB<SparseMatrix, Eigen::IncompleteLUT<double, int> >; // Preconditioned solver


    Vector f;
    Vector solutionDelta;
    Vector residual;
    SparseMatrix jacobian;


    constexpr static double deltaEta = 0.001;
    constexpr static unsigned int N = 101; // eta in [0,100]
    mutable double beta_=0;

    public:

    FalknerSkanSolver(const double& beta): beta_(beta){
        f.resize(N);
        solutionDelta.resize(N);
        residual.resize(N);
        jacobian.resize(N,N);


    }
};

#endif /* FALKNER_SKAN_SOLVER */