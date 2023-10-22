function graf
    N = 10000;

    tocke_na_loku = @(kot, radij) [radij + (radij * cos(kot)); radij + (radij * sin(kot))];

    x = 10 * rand(1, N);
    y = 10 * rand(1, N);

    znotraj_kroga = sqrt((x-5).^2 + (y-5).^2) <= 5;

    tocke_v_krogu = [x(znotraj_kroga); y(znotraj_kroga)];
    tocke_iz_kroga = [x(~znotraj_kroga); y(~znotraj_kroga)];

    figure;
    hold on;
    scatter(tocke_v_krogu(1, :), tocke_v_krogu(2, :), 'b', '.'); 
    scatter(tocke_iz_kroga(1, :), tocke_iz_kroga(2, :), 'r', '.'); 

    kot1 = linspace(0, 2 * pi, 100);
    radij1 = 5;
    tocke_lok = tocke_na_loku(kot1, radij1);
    plot(tocke_lok(1, :), tocke_lok(2, :), 'k', 'LineWidth', 2); 

    xlabel('x','FontSize',16)
    ylabel('y','FontSize',16)
    title({'Monte Carlo - Približna vrednost \pi'},'FontSize',16);
    legend('točke v krogu','točke iz kroga')

end
